#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>
#include <stdlib.h>

struct cmd_args {
	std::string ref_fp;
	std::string annot_fp;
	std::string sam_fp;
	int threshold;
	int min;
	int max;
	int skip;
	int s_per_level;
	std::string gene_fp;
	std::string mech_fp;
	std::string class_fp;
	std::string group_fp;
};

static void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: RarefactionAnalyzer\n");
        fprintf(stderr, "Contact: Chris Dean <cdean11@rams.colostate.edu>\n\n");
        fprintf(stderr, "Usage: rarefaction [options]\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "	-ref_fp		STR/FILE        Fasta file path\n");
	    fprintf(stderr, "	-annot_fp	STR/FILE        Annotation file path\n");
        fprintf(stderr, "	-sam_fp		STR/FILE        Sam file path\n");
	    fprintf(stderr, "	-gene_fp	STR/FILE        Output name for gene level resistome rarefaction distribution\n");
	    fprintf(stderr, "	-group_fp	STR/FILE        Output name for group level resistome rarefaction distribution\n");
	    fprintf(stderr, "	-mech_fp	STR/FILE        Output name for mechanism level resistome rarefaction distribution\n");
	    fprintf(stderr, "	-class_fp	STR/FILE        Output name for class level resistome rarefaction distribution\n");
	    fprintf(stderr, "	-min            INT             Starting sample level\n");
	    fprintf(stderr, "	-max            INT             Ending sample level\n");
	    fprintf(stderr, "	-skip           INT             Number of levels to skip\n");
	    fprintf(stderr, "	-samples        INT             Iterations per sampling level\n");
	    fprintf(stderr, "	-t              INT             Gene fraction threshold\n");

}

struct cmd_args 
inline parse_command_line(const int argc, const char *argv[]) {
	struct cmd_args arg;
	std::vector<std::string> args(argv, argv + argc);

        for(int i = 1; i < argc; i++) {
                if(args[i].compare("-ref_fp") == 0)
                        arg.ref_fp = args[++i];
		else if(args[i].compare("-annot_fp") == 0)
			arg.annot_fp = args[++i];
                else if(args[i].compare("-sam_fp") == 0)
                        arg.sam_fp = args[++i];
		else if(args[i].compare("-t") == 0)
                        arg.threshold = atoi(args[++i].c_str());
                else if(args[i].compare("-min") == 0)
                        arg.min = atoi(args[++i].c_str());
                else if(args[i].compare("-max") == 0)
                        arg.max = atoi(args[++i].c_str());
                else if(args[i].compare("-skip") == 0)
                        arg.skip = atoi(args[++i].c_str());
                else if(args[i].compare("-samples") == 0)
                        arg.s_per_level = atoi(args[++i].c_str());
		else if(args[i].compare("-gene_fp") == 0)
			arg.gene_fp = args[++i];
		else if(args[i].compare("-class_fp") == 0)
                        arg.class_fp = args[++i];
		else if(args[i].compare("-group_fp") == 0)
                        arg.group_fp = args[++i];
		else if(args[i].compare("-mech_fp") == 0)
                        arg.mech_fp = args[++i];
                else {
                        usage();
                        exit(EXIT_FAILURE);
                }
        }
	return arg;
}

#endif // ARGS_H
