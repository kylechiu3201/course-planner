#pragma once
#include <string>

class Command
{
public:
    static void get_command(std::string command);
    static void exit_prog();
};