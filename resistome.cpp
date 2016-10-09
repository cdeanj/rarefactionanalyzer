#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "resistome.hpp"
#include "utility.hpp"

resistome::resistome(cmd_args arguments) : args(arguments) {}

void resistome::process_gene_level(record &rec, const alignment &al) {
	rec.update_gene_hits();

	int pos_in_read = 0;
	int pos_in_gene = al.pos-1;

	int gene_length = rec.get_gene().length();

	for(int i = 0; i < al.cigar.size(); i++) {
		int occurrence = al.cigar[i].first;
		char operation = al.cigar[i].second;
		int start = pos_in_gene;
		int stop = start + occurrence;

		if(stop > gene_length) {
			stop = gene_length;
		}

		switch(operation) {
                        case 'M':
                                for(int i = start; i < stop; i++) {
                                        rec._base_hits[i] = 1;
                                        pos_in_gene++;
					pos_in_read++;
                                }
                                break;
                        case '=':
                                for(int i = start; i < stop; i++) {
                                        rec._base_hits[i] = 1;
                                        pos_in_gene++;
                                        pos_in_read++;
                                }
                                break;
                        case 'D':
                                pos_in_gene += occurrence;
                                break;
                        case 'N':
                                pos_in_gene += occurrence;
                                break;
                        case 'S':
                                pos_in_read += occurrence;
                                break;
                        case 'I':
                                pos_in_read += occurrence;
                                pos_in_gene += occurrence;
                                break;
                        case 'H':
                                break;
                        case 'P':
                                pos_in_gene += occurrence;
                                pos_in_read += occurrence;
                                break;
                        case 'X':
                                pos_in_gene += occurrence;
                                pos_in_read += occurrence;
                                break;
                        default:
                                break;
                }
	}
}


void resistome::reset(std::map<std::string,record> &records) {
	for(auto key = records.begin(); key != records.end(); ++key) {
		key->second.reset_base_hits();
		key->second.reset_gene_hits();
	}
}

samples resistome::generate_samples(std::map<std::string, record> &records, const std::vector<struct alignment> &alignments) {
	srand(unsigned(time(0)));

	int alignment_count = alignments.size();
	std::vector<int> sequence(alignment_count);
	std::iota(sequence.begin(), sequence.end(), 0);

	samples samp;

	for(int i = args.min; i <= args.max; i += args.skip) {
		for(int j = 0; j < args.s_per_level; j++) {
			random_shuffle(sequence.begin(), sequence.end(), utility::rando);
			int sample_size = round(((static_cast<double>(i)/100)*alignment_count));
			std::vector<int> chosen(sequence.begin(), sequence.begin()+sample_size);
			for(int k = 0; k < chosen.size(); k++) {
				std::string rname = alignments[chosen[k]].rname;
				auto it = records.find(rname);
				if(it == records.end()) {
					continue;
				}
				process_gene_level(records.find(rname)->second, alignments[chosen[k]]);
			}
			for(auto rec = records.begin(); rec != records.end(); ++rec) {
				if(rec->second.coverage() > args.threshold) {
					samp.gene_l[i].insert(rec->first);
				}
                        }
			reset(records);
		}
	}
	return samp;
}
