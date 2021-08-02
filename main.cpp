/* main.c

   Copyright (C) 2015-2018 Mariano Ruiz <mrsarm@gmail.com>
   This file is part of the helloworld C-project.

   The "helloworld C-project" is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   The project is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the "helloworld C-project" project; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Print the shell prompt, run after previous commands finishes
void print_prompt()
{
    cout << "> ";
}

// Awaits any user input, returns full line
string wait_for_input()
{
    string user_input;
    std::getline(std::cin, user_input);
    return user_input;
}


// 'parses' user command line input, essentially splits the line into 'command' and 'parameters', by creating vectors, subvectors and loops back to strings
string parse_command_line(string input_line)
{
    // if input is empty skip this paring round, and continue main shell while loop
    if (input_line.empty())
        return "";

    vector<string> strings;
    string vector_temp_str;
    istringstream f(input_line);

    // construct string array \ list \ vector
    while (getline(f, vector_temp_str, ' '))
    {
        // cout << s << endl;
        strings.push_back(vector_temp_str);
    }

    // extract command (first undelimited string)
    string command = strings[0];

    // create sub vector of parameters for command
    std::vector<string> parameters = {strings.begin() + 1, strings.end()};

    // create a new string out of parameters vectors, mainly for pretty printing
    string s;
    for (const auto &piece : parameters)
    {
        if (!s.empty())
        {
            s += "," + piece;
        }
        else
        {
            s += piece;
        }

    }
        cout << "Requested Command: " << command << ", Requested Parameters: " << s << endl;
        return "";
}

int main()
{
    while (true)
    {
        print_prompt();
        string user_input = wait_for_input();
        parse_command_line(user_input);
    }
    return 0;
}
