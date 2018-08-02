# Rarefaction Analyzer

## Overview

Rarefaction analyzer is a simple program that can be used to perform rarefaction analysis. This analysis is particularly useful when you wish to know the fraction of the target population that is captured in your sequence data versus the fraction of the target population that has not been described due to not sequencing deep enough. This is a standard analysis performed for microbiome research and is typically recommended for any kind of metagenomics where counts are of interest. Input to this tool includes a [FASTA](https://en.wikipedia.org/wiki/FASTA_format) formatted reference database, a [SAM](http://samtools.github.io/hts-specs/SAMv1.pdf) formatted alignment file, and a [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) formatted annotation database.

## Output

The output of this tool is four [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) text files, with the proportion of reads sampled in the first column and the number of unique genes, groups, mechanisms, or classes identified in the rarefied data. These outputs can be easilly graphed with common [R](https://www.r-project.org/about.html) packages like [ggplot2](http://ggplot2.org) or [Python](https://www.python.org) libraries such as [matplotlib](http://matplotlib.org). To graph, place the proportion of reads sampled (first column) on the x-axis and the number of unique genes, groups, mechanisms, or classes (second column) on the y-axis.

## Installation
```bash
$ git clone https://github.com/cdeanj/RarefactionAnalyzer.git
$ cd RarefactionAnalyzer
$ make
$ cp rarefaction /usr/local/bin
$ ./rarefaction
```

## Usage
```bash
$ ./rarefaction \
   -ref_fp ref.fa \
   -sam_fp alignments.sam \
   -annot_fp annotations.csv \
   -gene_fp gene.tsv \
   -group_fp group.tsv \
   -class_fp class.tsv \
   -mech_fp mech.tsv \
   -min 5 \
   -max 100 \
   -samples 1 \
   -t 80
```

## Options

| Option        | Type | Description   |
| ------------- |:----:|:-------------:|
| ref_fp        | FILE | Path to FASTA formatted reference database |
| annot_fp      | FILE | Path to CSV formatted annotation database  |
| sam_fp        | FILE | Path to SAM formatted alignment file       |
| gene_fp       | FILE | File to write gene level results to        |
| group_fp      | FILE | File to write group level results to       |
| class_fp      | FILE | File to write class level results to       |
| mech_fp       | FILE | File to write mechanism level results to   |
| min           | INT  | Starting sample level                      |
| max           | INT  | Ending sample level                        |
| skip          | INT  | Skip pattern                               |
| samples       | INT  | Number of samples to run                   |
| t             | INT  | Threshold to determine gene significance   |
