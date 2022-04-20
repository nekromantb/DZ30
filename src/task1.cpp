#include "task1.h"
#include <iostream>
#include <cpr/cpr.h>

cpr::Response userRequest (std::string command_request)
{
    if (command_request == "get")
        return cpr::Get(cpr::Url(("http://httpbin.org/"+command_request)));
    if (command_request == "post")
        return cpr::Post(cpr::Url(("http://httpbin.org/"+command_request)));
    if (command_request == "put")
        return cpr::Get(cpr::Url(("http://httpbin.org/"+command_request)));
    if (command_request == "delete")
        return cpr::Get(cpr::Url(("http://httpbin.org/"+command_request)));
    if (command_request == "patch")
        return cpr::Get(cpr::Url(("http://httpbin.org/"+command_request)));

}

void task1()
{
    std::cout << "Enter command to request" << std::endl;
    std::string userInput;
    std::cin >> userInput;
    if (userInput == "get" || userInput == "post"|| userInput == "put" || userInput == "delete" || userInput == "patch" )
    {
        cpr::Response r = userRequest(userInput);
        std::cout << r.text << std::endl;
    }
    else std::cout << "Invalid input! Request canceled. Program will stop automatically."<< std::endl;
}