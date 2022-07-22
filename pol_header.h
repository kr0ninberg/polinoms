#ifndef POL_HEADER_H
#define POL_HEADER_H
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

// structs and their functions

struct pol{
    int coef;
    int degree;
    pol *next;
};

struct pol_cont{
    int N;
    pol *i_pol;
    pol_cont *next;
};

template <typename T , typename P>
struct pair{
    T first;
    P second;
};

struct triple{
    uint ind;
    int a;
    int b;
};

std::string pol_v = "";
pol_cont *all_pols = nullptr;

void console_interface();
void help();
void file_opener(std::string);

pol*& pol_add_init(pol * , pol *);
pol*& pol_add_real(pol *& , pol*& , pol * , pol *);
pol*& pol_dec(pol * , pol *);
pol*& pol_comp(pol * , pol *);
pol*& mon_comp(pol * , pol *);
pair<pol,pol> pol_div(pol * , pol *);

pol*& pol_fill(std::string);
triple read_mononome(uint , std::string , bool first=false);
triple st_machine(uint , std::string , int);
uint skip_spaces(uint , std::string);
pair<uint , int> get_num(uint , std::string);
pair<uint , std::string> get_var(uint , std::string);
void set_var(std::string , bool force=false);

void pol_delete(pol *);
template<typename T>
T pol_val_in_dot(pol * , T);
pol*& pol_diff_simple(pol *);
pol*& pol_diff_full(pol *& , int amount=1);
void pol_append(pol *& , int , int);
void pol_printer(pol *);
void pol_clean_zeros(pol *&);
void pol_delete_el(pol *&);
pol*& pol_inversor(pol *);
pol*& pol_clone(pol *);

void pol_cont_renum();
void pol_cont_remove_el(pol_cont *&PC=all_pols , int N=-1);
void pol_cont_add_el(pol * , int N=-1);
void pol_cont_print_con();
pol*& pol_cont_get_pol(int);


#endif // POL_HEADER_H
