#include "task3.h"
#include <iostream>
#include <map>
#include <cpr/cpr.h>

class UserRequest
{
    cpr::Payload* userHeadersPayload = nullptr;
    std::string userGetRequestURL = "http://httpbin.org/post";
    std::map<std::string, std::string> userHeadersInput;
    std::string userTypeRequest;

public:

    UserRequest()
    {
        std::vector<cpr::Pair> userHeadersPairs;
        std::cout << "Waiting for users pairs to add in request header:" << std::endl;
        while (1)
        {
            std::string argument, value;
            std::cin >> argument;
            if (argument == "get" || argument == "post")
            {
                userTypeRequest = argument;
                break;
            }
            else {
                std:: cin >> value;
                userHeadersInput.insert(std::pair<std::string, std::string>(argument, value));
                userHeadersPairs.push_back(cpr::Pair(argument,value));
            }
        }
        if (userTypeRequest == "post") {
            userHeadersPayload = new cpr::Payload(userHeadersPairs.begin(), userHeadersPairs.end());
        }
        else
        {
            std::string req;
            for (auto it = userHeadersInput.begin(); it != userHeadersInput.end();++it)
            {
                if (req == "") req += it->first + "="+it->second;
                else req += "&" + it->first + "="+it->second;
            }
            userGetRequestURL = "http://httpbin.org/get?"+req;
        }
    }

    std::string getURL()
    {
        return userGetRequestURL;
    }

    cpr::Payload* getPayload()
    {
        return userHeadersPayload;
    }

    std::string getTypeRequest()
    {
        return userTypeRequest;
    }
};

void task3()
{
    std::cout << "Starting to form new request." << std::endl;
    UserRequest* input = new UserRequest();
    if (input->getTypeRequest() == "get")
    {
        cpr::Response r = cpr::Get(cpr::Url(input->getURL()));
        std::cout << r.text << std::endl;
    }
    else
    {
        cpr::Response r = cpr::Post(cpr::Url(input->getURL()),*input->getPayload());
        std::cout << r.text << std::endl;
    }

}