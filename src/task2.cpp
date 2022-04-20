#include "task2.h"
#include <iostream>
#include <cpr/cpr.h>

class Headers
{
    std::string header;

public:

    std::string getHeader()
    {
        return header;
    }

    void setHeaderFromHTML(cpr::Response response)
    {
        int first_header, length_header;
        first_header = response.text.find("<h1>") +4;
        length_header = response.text.find("</h1>") - first_header;
        header = response.text.substr(first_header,length_header);
    }
};

void task2()
{
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"accept","text/html"}}));
    Headers headerOutput;
    headerOutput.setHeaderFromHTML(r);
    std::cout << headerOutput.getHeader()<< std::endl;

}