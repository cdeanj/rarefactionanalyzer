# Rarefaction Analyzer

## Overview
Rarefaction analyzer is a simple program that can be used to perform rarefaction analysis. This analysis is particularly useful when you wish to know the fraction of the target population that is captured in your sequence data versus the fraction of the target population that has not been described due to not sequencing deep enough. This is a standard analysis performed for microbiome research and is typically recommended for any kind of metagenomics where counts are of interest. Input to this tool includes a [FASTA](https://en.wikipedia.org/wiki/FASTA_format) formatted reference database, a [SAM](http://samtools.github.io/hts-specs/SAMv1.pdf) formatted alignment file, and a [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) formatted annoation database.

## Output
The output of this tool is four [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) text files, with the proportion of reads sampled in the first column and the number of unique genes, groups, mechanisms, or classes identified in the rarefied data. These outputs can be easilly graphed with common [R](https://www.r-project.org/about.html) packages like [ggplot2](http://ggplot2.org) or [Python](https://www.python.org) libraries such as [matplotlib](http://matplotlib.org). To graph, place the proportion of reads sampled (first column) on the x-axis and the number of unique genes, groups, mechanisms, or classes (second column) on the y-axis.

## Installation
```bash
$ git clone https://github.com/cdeanj/RarefactionAnalyzer.git
$ cd RarefactionAnalyzer
$ make
$ ./rarefaction
```

## Usage
```bash
$ ./rarefaction [options]
```

## Options

##### `-ref_fp`
Path to fasta formatted reference sequence
```bash
$ -ref_fp /path/to/your/reference.fasta
```

##### `-sam_fp`
Path to SAM formatted alignment file
```bash
$ -sam_fp /path/to/your/alignment.sam
```

##### `-annot_fp`
Path to CSV formatted annotation database
```bash
$ -annot_fp /path/to/your/annotation.fasta
```

##### `-min`
Starting sample level
```bash
$ -min 5
```

##### `-max`
Ending sample level
```bash
$ -max 100
```

##### `-skip`
Skip pattern
```bash
$ -skip 5
```

##### `-samples`
Number of samples to run
```bash
$ -samples 5
```

##### `-t`
Threshold parameter for determining gene significance
```bash
$ -t 80
```

