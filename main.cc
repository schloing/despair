#include <iostream>
#include <stack>
#include <arithmetic.h>
#include <constant.h>
#include <node.h>
#include <return.h>
#include <rtti.h>
#include <start.h>
#include <string.h>

bool is_valid_char_for_var_name(char c)
{
    return std::isalnum(c) || c == '_';
}

despair::Return parse(std::string_view code)
{
    despair::Start parse_main;
    std::string lit;
    std::stack<despair::IRNode*> context; // parser context

    for (std::size_t i = 0; i < code.size(); i++) {
        if (!code[i]) {
            break;
        }

        switch (code[i]) {
        case '-':
        {
            despair::Negate neg { nullptr }; // FIXME
            context.push(&neg);
            break;
        }

        case '+':
        case '*':
        case '/':
            break;

        case ';':
            while (!context.empty()) {
                context.pop();
            }
            break;
        }

        if (std::isdigit(code[i])) {
            // number literal
            do {
                lit.push_back(code[i]);
                i++;
            } while (std::isdigit(code[i]));

            int v { std::stoi(lit) }; // TODO: handle exception
            despair::Constant var { &parse_main, new despair::TypeInteger(v) };
            if (!context.empty()) {
                if (auto* neg = despair::dyn_cast<despair::Negate>(context.top())) {
                    neg->a = &var;
                }
            }
            lit.clear();
        }
        else if (is_valid_char_for_var_name(code[i])) {
            // string literal, keyword or symbol
            do {
                lit.push_back(code[i]);
                i++;
            } while (is_valid_char_for_var_name(code[i]));

            if (lit == "return") {
                // parse return
            }

            lit.clear();
        }
    }

    return despair::Return (nullptr, nullptr);
}

int main()
{
    std::string code = "return 1 + 2 * 3 + -5";
    std::cout << "parsing: " << code << std::endl;
    despair::Return test = parse(code);
//  despair::Start* func = new despair::Start();
//  despair::Constant num5 (func, new despair::TypeInteger(5));
//  despair::Constant num6 (func, new despair::TypeInteger(6));
//  despair::Multiply retvalexpr (&num5, &num6);
//  despair::Return retexpr (func, retvalexpr.peephole());

    return 0;
}
