#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "fasta_reader.hpp"
#include "sam_reader.hpp"
#include "resistome.hpp"
#include "args.hpp"

using namespace std;

int main(const int argc, const char *argv[]) {
	/*if(argc != 17) {
		usage();
		exit(EXIT_FAILURE);
	}*/

	struct cmd_args args;
	args = parse_command_line(argc, argv);

	fasta_reader fr(args.ref_fp);
	map<string, record> records = fr.read();

	sam_reader sr(args.sam_fp);
	vector<struct alignment> alignments = sr.read();

	annotation_reader ar(args.annot_fp);
	map<string, annotation_fields> annotations = ar.read();

	resistome res(args);
	samples samp = res.generate_samples(records, alignments);

	for(auto key = samp.gene_l.begin(); key != samp.gene_l.end(); ++key) {
		for(auto val = key->second.begin(); val != key->second.end(); ++val) {
			if(annotations.count(*val) > 0) {
				samp.class_l[key->first].insert(annotations[*val]._class_level);
				samp.mechanism_l[key->first].insert(annotations[*val]._mechanism_level);
				samp.group_l[key->first].insert(annotations[*val]._group_level);
			}
		}
	}


	ofstream ofs_gene(args.prefix + "_gene.tab");	
	for(auto key = samp.gene_l.begin(); key != samp.gene_l.end(); ++key) {
		ofs_gene << key->first << "\t" << key->second.size() << endl;
	}

	ofstream ofs_class(args.prefix + "_class.tab");
	for(auto key = samp.class_l.begin(); key != samp.class_l.end(); ++key) {
		ofs_class << key->first << "\t" << key->second.size() << endl;
	}

	ofstream ofs_mech(args.prefix + "_mechanism.tab");
	for(auto key = samp.mechanism_l.begin(); key != samp.mechanism_l.end(); ++key) {
		ofs_mech << key->first << "\t" << key->second.size() << endl;
        }

	ofstream ofs_group(args.prefix + "_group.tab");
	for(auto key = samp.group_l.begin(); key != samp.group_l.end(); ++key) {
		ofs_group << key->first << "\t" << key->second.size() << endl;
        }

	
	
	return 0;
}
