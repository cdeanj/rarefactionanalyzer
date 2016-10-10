# Rarefaction Analyzer

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

##### `-prefix`
Prefix for output files
```bash
$ -prefix my_results
```
