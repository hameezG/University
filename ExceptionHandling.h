#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H

#include <exception>
#include <string>

using namespace std;

// Base class for custom exceptions
class BaseException : public std::exception {
public:
    BaseException(const string& message) : message(message) {}
    virtual ~BaseException() noexcept {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }

private:
    string message;
};




class InvalidInputException : public BaseException {
public:
    InvalidInputException(const string& message) : BaseException(message) {}
};

class AuthenticationException : public BaseException {
public:
    AuthenticationException(const string& message) : BaseException(message) {}
};

class PlantNotFoundException : public BaseException {
public:
    PlantNotFoundException(const string& message) : BaseException(message) {}
};

#endif
