#ifndef VTR_UTIL_H
#define VTR_UTIL_H

#include <vector>
#include <string>
#include <cstdarg>
#include <array>

namespace vtr {

    //Splits the string 'text' along the specified delimiter characters in 'delims'
    //The split strings (excluding the delimiters) are returned
    std::vector<std::string> split(const char* text, const std::string delims=" \t\n");
    std::vector<std::string> split(const std::string& text, const std::string delims=" \t\n");

    //Splits off the name and extension (including ".") of the specified filename
    std::array<std::string,2> split_ext(const std::string& filename);

    //Returns 'input' with the first instance of 'search' replaced with 'replace'
    std::string replace_first(const std::string& input, const std::string& search, const std::string& replace);

    //Returns 'input' with all instances of 'search' replaced with 'replace'
    std::string replace_all(const std::string& input, const std::string& search, const std::string& replace);

    //Returns a std::string formatted using a printf-style format string
    std::string string_fmt(const char* fmt, ...);

    //Returns a std::string formatted using a printf-style format string taking
    //an explicit va_list
    std::string vstring_fmt(const char* fmt, va_list args);

    //Returns the basename of path (i.e. the last filename component)
    //  For example, the path "/home/user/my_files/test.blif" -> "test.blif"
    std::string basename(const std::string& path);

    //Returns the dirname of path (i.e. everything except the last filename component)
    //  For example, the path "/home/user/my_files/test.blif" -> "/home/user/my_files/"
    std::string dirname(const std::string& path);

    //Joins a sequence by a specified delimeter
    //  For example the sequence {"home", "user", "my_files", "test.blif"} with delim="/"
    //  would return "home/user/my_files/test.blif"
    template<typename Iter>
    std::string join(Iter begin, Iter end, std::string delim);

    template<typename Container>
    std::string join(Container container, std::string delim);

    /*
     * Legacy c-style function replacements, typically these add extra error checking
     * and/or correct 'unexpected' behaviour of the standard c-functions
     */
    constexpr size_t bufsize = 32768; /* Maximum line length for various parsing proc. */
    char* strncpy(char *dest, const char *src, size_t size);
    char* strdup(const char *str);
    char* strtok(char *ptr, const char *tokens, FILE * fp, char *buf);
    FILE* fopen(const char *fname, const char *flag);
    int fclose(FILE* f);
    char* fgets(char *buf, int max_size, FILE * fp);

    int atoi(const std::string& value);
    unsigned atou(const std::string& value);
    float atof(const std::string& value);
    double atod(const std::string& value);

    /*
     * File utilities
     */
    int get_file_line_number_of_last_opened_file();
    bool file_exists(const char * filename);
    bool check_file_name_extension(const char* file_name, 
                                   const char* file_extension);


    extern std::string out_file_prefix;

    /*
     * Legacy ReadLine Tokening
     */
    std::vector<std::string> ReadLineTokens(FILE * InFile, int *LineNum);

    /*
     * Template implementations
     */
    template<typename Iter>
    std::string join(Iter begin, Iter end, std::string delim) {
        std::string joined_str;
        for(auto iter = begin; iter != end; ++iter) {
            joined_str += *iter;
            if(iter != end - 1) {
                joined_str += delim;
            }
        }
        return joined_str;
    }

    template<typename Container>
    std::string join(Container container, std::string delim) {
        return join(std::begin(container), std::end(container), delim);
    }
}

#endif
