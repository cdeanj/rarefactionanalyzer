#ifndef ANNOTATION_READER_H
#define ANNOTATION_READER_H

#include <vector>
#include <string>
#include <map>

struct annotation_fields {
        annotation_fields() {}
        annotation_fields(std::string class_l, std::string mechanism_l, std::string group_l)
                : _class_level(class_l), _mechanism_level(mechanism_l), _group_level(group_l)
        {}

        std::string _class_level;
        std::string _mechanism_level;
        std::string _group_level;
};

class annotation_reader {
public:
	annotation_reader(std::string fp);
	std::map<std::string, annotation_fields> read();
private:
	std::string _fp;
};

#endif // ANNOTATION_READER_H
