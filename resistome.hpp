#ifndef RESISTOME_HPP
#define RESISTOME_HPP

#include "args.hpp"
#include "record.hpp"
#include "alignment.hpp"
#include "annotation_reader.hpp"

#include <map>
#include <set>
#include <vector>
#include <string>

struct samples {
	std::map<int, std::set<std::string> > gene_l;
	std::map<int, std::set<std::string> > class_l;
	std::map<int, std::set<std::string> > mechanism_l;
	std::map<int, std::set<std::string> > group_l;
};

class resistome {
public:
	resistome(cmd_args arguments);
	void process_gene_level(record &rec, const alignment &al);
	samples generate_samples(std::map<std::string, record> &records, const std::vector<struct alignment> &alignments);
	void reset(std::map<std::string,record> &records);
private:
	cmd_args args;
};

#endif // RESISTOME_HPP
