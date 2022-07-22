#include "pol_header.h"

extern std::string pol_v;
extern pol_cont *all_pols;

template <typename T>
void p_print(T smt);
template<typename T>
T pow(T , int);

int main()
{
    console_interface();
    return 0;
}

// additional functions begin

template<typename T>
T pow(T x , int degree){
    if(degree == 0) return 1;
    if(!(degree & 1)){
        return pow(x * x , degree / 2);
    }
    else{
        return x * pow(x , --degree);
    }
}

template <typename T>
void p_print(T smt){
    std::cout << smt << '\n';
    return;
}

void console_interface(){
    bool no_exit = true;
    help();
    while(no_exit){
        try{
            std::string s;
            std::cin >> s;
            if(s == "sum"){
                std::cout << "enter pol numbers: ";
                int a , b;
                std::string s1 , s2;
                std::cin >> s1 >> s2;
                try {
                    a = std::stoi(s1);
                    b = std::stoi(s2);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol t = *(pol_add_init(pol_cont_get_pol(a) , pol_cont_get_pol(b)));
                std::cout << "polinome: ";
                pol_printer(&t);
                std::cout << "do you want to add pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(&t , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "\e[32;1mOk\e[0m\n";
            }
            else if(s == "dec" || s == "decrement" || s == "difference"){
                std::cout << "enter pol numbers: ";
                int a , b;
                std::string s1 , s2;
                std::cin >> s1 >> s2;
                try{
                    a = std::stoi(s1);
                    b = std::stoi(s2);
                } catch(...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol t = *(pol_dec(pol_cont_get_pol(a) , pol_cont_get_pol(b)));
                std::cout << "polinome: ";
                pol_printer(&t);
                std::cout << "do you want to add pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(&t , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "\e[32;1mOk\e[0m\n";
            }
            else if(s == "mul" || s == "multiply"){
                std::cout << "enter pol numbers: ";
                int a , b;
                std::string s1 , s2;
                std::cin >> s1 >> s2;
                try {
                    a = std::stoi(s1);
                    b = std::stoi(s2);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol t = *(pol_comp(pol_cont_get_pol(a) , pol_cont_get_pol(b)));
                std::cout << "polinome: ";
                pol_printer(&t);
                std::cout << "do you want to add pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(&t , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "\e[32;1mOk\e[0m\n";
            }
            else if(s == "div" || s == "divide"){
                std::cout << "enter pol numbers: ";
                int a , b;
                std::string s1 , s2;
                std::cin >> s1 >> s2;
                try {
                    a = std::stoi(s1);
                    b = std::stoi(s2);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol_clean_zeros(pol_cont_get_pol(b));
                pair<pol,pol> res1 = pol_div(pol_cont_get_pol(a) , pol_cont_get_pol(b));
                pol *&P1 = res1.first.next;
                pol *&P2 = res1.second.next;
                pol_clean_zeros(P1);
                pol_clean_zeros(P2);
                std::cout << "Result polinome: ";
                pol_printer(P1);
                std::cout << "Remainder polinome: ";
                pol_printer(P2);
                std::cout << "do you want to add result pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(P1 , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "do you want to add remainder pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(P2 , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "\e[32;1mOk\e[0m\n";
            }
            else if(s == "val" || s == "value"){
                int a , val;
                std::cout << "enter num of pol: ";
                std::string s1 , s2;
                std::cin >> s1;
                try{
                    a = std::stoi(s1);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "enter val: ";
                std::cin >> s2;
                try{
                    val = std::stoi(s2);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "value: " << pol_val_in_dot(pol_cont_get_pol(a) , val) << '\n';
            }
            else if(s == "dif" || s == "differentiate"){
                int a , b;
                std::cout << "enter polinom container number: ";
                std::string s1 , s2;
                std::cin >> s1;
                try{
                    a = std::stoi(s1);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "enter differentiate degree: ";
                std::cin >> s2;
                try{
                    b = std::stoi(s2);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol *t = pol_diff_full(pol_cont_get_pol(a) , b);
                std::cout << "polinome: ";
                pol_printer(t);
                std::cout << "do you want to add pol in container? [Y/n] ";
                std::cin >> s;
                if(s == "y"){
                    pol_cont_add_el(t , -1);
                }
                else if(s == "n"){}
                else{
                    throw std::string("console_interface: wrong parameters");
                }
            }
            else if(s == "add"){
                std::cout << "enter polinome position in contaner (-1: in the end): ";
                int t;
                std::string s1;
                std::cin >> s1;
                try{
                    t = std::stoi(s1);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                std::cout << "enter polinome: ";
                std::string s;
                std::getline(std::cin , s);
                std::getline(std::cin , s);
                pol_cont_add_el(pol_fill(s) , t);
                pol_cont_renum();
                std::cout << "\e[32;1msuccess\e[0m\n";
            }
            else if(s == "del" || s == "delete"){
                int t;
                std::cout << "enter polinome position in contaner: ";
                std::string s1;
                std::cin >> s1;
                try{
                    t = std::stoi(s1);
                } catch (...){
                    throw std::string("console_interface: wrong parameters");
                }
                pol_cont_remove_el(all_pols , t);
                std::cout << "\e[32;1msuccess\e[0m\n";
            }
            else if(s == "clr" || s == "clear"){
                pol_cont_remove_el();
                std::cout << "\e[32;1msuccess\e[0m\n";
            }
            else if(s == "ptc" || s == "print-container"){
                pol_cont_print_con();
            }
            else if(s == "exit" || s == "q"){
                no_exit  = false;
                std::cout << "\e[32;1msuccess\e[0m\n";
            }
            else if(s == "rdf" || s == "read-file"){
                file_opener("file.txt");
                std::cout << "\e[32;1msuccess\e[0m\n";
            }
            else if(s == "help"){
                help();
            }
            else if(s == "clean"){
                std::cout << "\e[1J\e[1;1H";
            }
            else if(s == ""){
                std::cout << "\e[1;31mERROR\e[0;1m : input stream is not working correctly!\e[0m\n";
                exit(0);
            }
            else {
                throw std::string("console_interface: wrong command");
            }
        } catch(std::string s){
            std::cout << "\e[1;31mWARNING\e[0;1m :" << s << "!\e[0m\n";
        } catch(...) {
            std::cout << "\e[1;31mWARNING\e[0;1m : unidentified error" << "!\e[0m\n";
        }
    }
    return;
}

void help(){
    std::cout << "\e[1mAVAILABLE COMMANDS\e[0m" << "\n";
    std::cout << "\t\e[36madd\e[0m - to add polinom to container" << "\n\n";
    std::cout << "\t\e[36mrdf\e[0m or \e[36mread-file\e[0m - read polinoms from file" << "\n\n";
    std::cout << "\t\e[36mptc\e[0m or \e[36mprint-container\e[0m - print container" << "\n\n";
    std::cout << "\t\e[36mdel\e[0m or \e[36mdelete\e[0m - remove polinom from container" << "\n\n";
    std::cout << "\t\e[36mclr\e[0m or \e[36mclear\e[0m - to remove all polinoms from container" << "\n\n";
    std::cout << "\t\e[36msum\e[0m - to find sum of two polinoms" << "\n\n";
    std::cout << "\t\e[36mdec\e[0m, \e[36mdecrement\e[0m or \e[36mdifference\e[0m - to find difference of two polinoms" << "\n\n";
    std::cout << "\t\e[36mmul\e[0m or \e[36mmultiply\e[0m - to find composition of two polinoms" << "\n\n";
    std::cout << "\t\e[36mdiv\e[0m or \e[36mdivide\e[0m - to find quotient of two polinoms" << "\n\n";
    std::cout << "\t\e[36mval\e[0m or \e[36mvalue\e[0m - to find value of polinom with readen parameter" << "\n\n";
    std::cout << "\t\e[36mdif\e[0m or \e[36mdifferentiate\e[0m - to find derivative of polinom" << "\n\n";
    std::cout << "\t\e[36mclean\e[0m - to clear the terminal screen" << "\n\n";
    std::cout << "\t\e[36mhelp\e[0m - to display this help" << "\n\n";
    std::cout << "\t\e[36mexit\e[0m or \e[36mq\e[0m - to exit from program" << "\n";
    //std::cout << "\t\e[36m\e[0m or \e[36m\e[0m" << "\n";
    return;
}

void file_opener(std::string s){
    std::ifstream fin(s);
    int a = 0;
    while(fin){
        a++;
        std::string s1;
        std::getline(fin , s1);
        pol_cont_add_el(pol_fill(s1) , -1);
        pol_cont_renum();
    }
    pol_cont_remove_el(all_pols , a);
    return;
}

// additional functions end
// pol functions begin

pol*& pol_add_init(pol *P1 , pol *P2){
    pol *t1 = new pol;
    t1->next = nullptr;
    pol *&t2 = t1->next;
    pol *&t3 = pol_add_real(t1 , t2 , P1 , P2);
    return t3->next;
}

pol*& pol_add_real(pol *&t1 , pol *&t2 , pol *P1 , pol *P2){
    if(P1 == nullptr && P2 == nullptr) {
        return t1;
    }
    if(P1 == nullptr){
        pol_append(t2 , P2->coef , P2->degree);
        return pol_add_real(t1 , t2->next , P1 , P2->next);
    }
    if(P2 == nullptr){
        pol_append(t2 , P1->coef , P1->degree);
        return pol_add_real(t1 , t2->next , P1->next , P2);
    }
    if(P2->degree > P1->degree){
        pol_append(t2 , P2->coef , P2->degree);
        return pol_add_real(t1 , t2->next , P1 , P2->next);
    }
    if(P1->degree > P2->degree){
        pol_append(t2 , P1->coef , P1->degree);
        return pol_add_real(t1 , t2->next , P1->next , P2);
    }
    if(P1->degree == P2->degree){
        pol_append(t2 , P1->coef + P2->coef , P1->degree);
        return pol_add_real(t1 , t2->next , P1->next , P2->next);
    }
    throw std::string("pol_add_real: mustn't be here");
}

pol*& pol_dec(pol *P1 , pol *P2){
    return pol_add_init(P1 , pol_inversor(P2));
}

pol*& pol_comp(pol *P1 , pol *P2){
    pol *t1 = new pol;
    t1->next = nullptr;
    pol*& t2 = t1->next;
    while(P1 != nullptr){
        pol* p2 = P2;
        while (p2 != nullptr) {
            t1->next = pol_add_init(t1->next , mon_comp(P1 , p2));
            p2 = p2->next;
        }
        P1 = P1->next;
    }
    return t2;
}

pol*& mon_comp(pol *p1 , pol *p2){
    pol *t1 = new pol;
    t1->next = new pol;
    pol*& t2 = t1->next;
    t1->next->coef = p1->coef * p2->coef;
    t1->next->degree = p1->degree + p2->degree;
    t1->next->next = nullptr;
    return t2;
}

pair<pol,pol> pol_div(pol *P1 , pol *P2){
    if(P2 == nullptr){
        throw std::string("pol_div: division by zero");
    }
    /*pol *t1 = p1;
    int n = 0;
    while(t1 != nullptr){
        if(t1->degree < P2->degree){
            break;
        }
        int p_coef , p_degree;
        p_coef = t1->coef / P2->coef;
        p_degree = t1->degree - P2->degree;
        pol *t = new pol;
        t->next = nullptr;
        t->coef = p_coef;
        t->degree = p_degree;
        p1 = pol_dec(p1 , pol_comp(P2 , t));
        res->next = pol_add_init(res->next , t);
        t1 = t1->next;
    }*/
    pol *p1 = new pol;
    p1->next = pol_clone(P1);
    int gone = 0;
    pol *t1 = p1->next;
    pol *res1 = new pol;
    res1->next = nullptr;
    while(t1 != nullptr){
        if(t1->degree < P2->degree) break;
        int p_coef = t1->coef / P2->coef;
        int p_deg = t1->degree - P2->degree;
        pol_append(res1->next , p_coef , p_deg);
        pol res_last;
        res_last.coef = p_coef;
        res_last.degree = p_deg;
        res_last.next = nullptr;
        p1->next = pol_dec(p1->next , pol_comp(P2 , &res_last));
        gone++;
        t1 = p1->next;
        for(int q = 0 ; q < gone ; q++){
            t1 = t1->next;
        }
    }
    pair<pol,pol> a;
    a.first = *(res1);
    a.second = *(p1);
    return a;
}

template<typename T>
T pol_val_in_dot(pol *P , T x){
    T y = 0;
    while(P != nullptr){
        y += P->coef * pow(x , P->degree);
        P = P->next;
    }
    return y;
}

pol*& pol_diff_simple(pol *P){
    if(P == nullptr) throw std::string("pol_diff_simple: P is nullptr");
    pol *t1 = new pol;
    t1->next = new pol;
    t1->next->next = nullptr;
    t1->next->coef = P->coef;
    t1->next->degree = P->degree;
    P = P->next;
    pol *t2 = t1->next;
    while(P != nullptr){
        t2->next = new pol;
        t2->next->next = nullptr;
        t2->next->coef = P->coef;
        t2->next->degree = P->degree;
        P = P->next;
        t2 = t2->next;
    }
    if(t1->next->degree == 0){
        pol_delete_el(t1->next);
        if(t1->next == nullptr) return t1->next;
        t1->next->coef *= t1->next->degree--;
    }
    else t1->next->coef *= t1->next->degree--;
    t2 = t1->next;
    if(t1->next == nullptr) return t1->next;
    while(t2->next != nullptr){
        if(t2->next->degree == 0) pol_delete_el(t2->next);
        else{
            t2->next->coef *= t2->next->degree--;
            t2 = t2->next;
        }
    }
    return t1->next;
}

pol*& pol_diff_full(pol *&P , int amount){
    if(P == nullptr) return P;
    if(amount < 0){
        throw std::string("pol_diff_full: amount is lower than 0");
        return P;
    }
    pol *&t = pol_diff_simple(P);
    for(int q = 1 ; q < amount ; q++){
        if(t == nullptr) return t;
        t = pol_diff_simple(t);
    }
    return t;
}

// polinom reader begin

pol*& pol_fill(std::string s){
    pol *t1 = new pol;
    t1->next = nullptr;
    pol *&t2 = t1->next;
    uint ind = 0;
    bool first = true;
    while(ind < s.length()){
        triple t;
        try{
            t = read_mononome(ind , s , first);
        }catch(std::string s){
            if(s == "read_mononome: nothing to read"){
                t2 = new pol;
                t2->next = nullptr;
                t2->coef = 0;
                t2->degree = 0;
                return t2;
            }
            std::cout << "\e[1;31mERROR\e[0;1m :" << s << "!\e[0m\n";
            t1->next = nullptr;
            return t2;
        }catch(...){
            exit(0);
        }
        first = false;
        ind = t.ind;
        pol t3;
        t3.next = nullptr;
        t3.coef = t.a;
        t3.degree = t.b;
        t1->next = pol_add_init(t1->next , &t3);
    }
    return t2;
}

triple read_mononome(uint ind , std::string s , bool first){
    triple smres;
    triple res;
    int state = 7;
    bool neg = false;
    ind = skip_spaces(ind , s);
    // read sign
    if(ind >= s.length()){
        throw std::string("read_mononome: nothing to read");
        return res;
    }
    if(first){
        state = 1;
        if(s[ind] == '-'){ // если знак -
            neg = true;
            ind++;
        }
        else if(s[ind] == '+'){ // если знак +
            ind++;
        }
        ind = skip_spaces(ind , s);
        if(ind >= s.length()){
            throw std::string("read_mononome: nothing after sign (first)");
            return res;
        }
    }
    else{
        smres = st_machine(ind , s , state);
        ind = smres.ind;
        state = smres.a;
        neg = smres.b;
        if(ind >= s.length()){
            throw std::string("read_mononome: nothing after sign");
            return res;
        }
    }
    smres = st_machine(ind , s , state); // переход от 1 состояния
    ind = smres.ind;
    state = smres.a;
    // read coefficient
    if(state == 2){
        if(neg){ // присв коэф
            res.a = -smres.b;
        }
        else{
            res.a = smres.b;
        }
        if(ind < s.length()){ // если не последнее
            smres = st_machine(ind , s , state); // переход от 2 состояния
            ind = smres.ind;
            state = smres.a;
        }
        if(smres.a == 7 || (ind >= s.length() && state == 2)){ // если последнее
            res.b = 0;
            res.ind = smres.ind;
            return res;
        }
    }
    else if(state == 4){ // если не было коэф
        if(neg){
            res.a = -1;
        }
        else{
            res.a = 1;
        }
    }
    // read degree
    if(smres.a == 3){
        if(ind >= s.length()){
            throw std::string("read_mononome: nothing after '*'");
        }
        smres = st_machine(smres.ind , s , state);
        state = smres.a;
        ind = smres.ind;
    }
    if(ind < s.length()){
        smres = st_machine(ind , s , state);
        ind = smres.ind;
        state = smres.a; // state == 5
    }
    if(state == 7 || ind >= s.length()){ // если после x ничего
        res.b = 1;
        res.ind = ind;
        return res;
    }
    smres = st_machine(ind , s , state);
    ind = smres.ind;
    state = smres.a; // state == 6
    res.b = smres.b;
    res.ind = ind;
    return res;
}

triple st_machine(uint ind , std::string s , int state){
    triple smres;
    if(state == 1){
        if(s[ind] >= '0' && s[ind] <= '9'){
            pair<uint , int> t = get_num(ind , s);
            smres.ind = skip_spaces(t.first , s);
            smres.a = 2;
            smres.b = t.second;
        }
        else if((s[ind] <= 'z' && s[ind] >= 'a') || (s[ind] <= 'Z' && s[ind] >= 'A') || (s[ind] == '_')){
            pair<uint , std::string> t = get_var(ind , s);
            set_var(t.second);
            smres.ind = skip_spaces(t.first , s);
            smres.a = 4;
            smres.b = 1;
        }
        else throw std::string("st_machine: error 1");
    }
    else if(state == 2){
        if((s[ind] <= 'z' && s[ind] >= 'a') || (s[ind] <= 'Z' && s[ind] >= 'A') || (s[ind] == '_')){
            pair<uint , std::string> t = get_var(ind , s);
            set_var(t.second);
            smres.ind = skip_spaces(t.first , s);
            smres.a = 4;
            smres.b = 1;
        }
        else if(s[ind] == '*'){
            ind++;
            smres.ind = skip_spaces(ind , s);
            smres.a = 3;
            smres.b = 0;
        }
        else if(s[ind] == '-' || s[ind] == '+'){
            smres.ind = ind;
            smres.a = 7;
            smres.b = 0;
        }
        else throw std::string("st_machine: error 2");
    }
    else if(state == 3){
        if((s[ind] <= 'z' && s[ind] >= 'a') || (s[ind] <= 'Z' && s[ind] >= 'A') || (s[ind] == '_')){
            pair<uint , std::string> t = get_var(ind , s);
            set_var(t.second);
            smres.ind = skip_spaces(t.first , s);
            smres.a = 4;
            smres.b = 1;
        }
        else throw std::string("st_machine: error 3");
    }
    else if(state == 4){
        if(s[ind] == '^'){
            ind++;
            smres.ind = skip_spaces(ind , s);
            smres.a = 5;
            smres.b = 0;
        }
        else if(s[ind] == '-' || s[ind] == '+'){
            smres.ind = ind;
            smres.a = 7;
            smres.b = 0;
        }
        else throw std::string("st_machine: error 4");
    }
    else if(state == 5){
        if(s[ind] >= '0' && s[ind] <= '9'){
            pair<uint , int> t = get_num(ind , s);
            smres.ind = skip_spaces(t.first , s);
            smres.a = 6;
            smres.b = t.second;
        }
        else throw std::string("st_machine: error 5");
    }
    else if(state == 6){
        if(s[ind] == '-' || s[ind] == '+'){
            smres.ind = ind;
            smres.a = 7;
            smres.b = 0;
        }
        else throw std::string("st_machine: error 6");
    }
    else if(state == 7){
        if(s[ind] == '-'){
            ind++;
            smres.ind = skip_spaces(ind , s);
            smres.a = 1;
            smres.b = 1;
        }
        else if(s[ind] == '+'){
            ind++;
            smres.ind = skip_spaces(ind , s);
            smres.a = 1;
            smres.b = 0;
        }
        else throw std::string("st_machine: error 7");
    }
    return smres;
}

uint skip_spaces(uint ind , std::string s){
    while(ind < s.length() && (s[ind] == ' ' || s[ind] == '\t')){
        ind++;
    }
    return ind; // ind can be equal s.lenght
}

pair<uint , int> get_num(uint ind , std::string s){
    pair<uint , int> t;
    int num = 0;
    while(ind < s.length() && s[ind] <= '9' && s[ind] >= '0') num = num * 10 + s[ind++] - '0';
    t.first = ind;
    t.second = num;
    return t;
}

pair<uint , std::string> get_var(uint ind , std::string s){
    pair<uint , std::string> t;
    std::string res = "";
    while(ind < s.length() && ((s[ind] <= 'z' && s[ind] >= 'a') || (s[ind] <= 'Z' && s[ind] >= 'A') || (s[ind] == '_'))) {
        res += s[ind++];
    }
    t.first = ind;
    t.second = res;
    return t;
}

void set_var(std::string s , bool force){
    if(pol_v == "" || force) pol_v = s;
    else if(pol_v != s && !force) throw std::string("set_var: wrong var");
    return;
}

// polinom reader begin

void pol_delete(pol *P){
    if(P == nullptr) return;
    pol *t = P->next;
    delete P;
    pol_delete(t);
    return;
}

void pol_append(pol *&p , int coef , int degree){
    if(p == nullptr){
        pol *t = new pol;
        t->coef = coef;
        t->degree = degree;
        t->next = nullptr;
        p = t;
        return;
    }
    pol *t = new pol;
    t->coef = coef;
    t->degree = degree;
    t->next = nullptr;
    pol *q = p;
    while(q->next != nullptr){
        q = q->next;
    }
    q->next = t;
    return;
}

void pol_printer(pol *P){
    if(P == nullptr){
        std::cout << "0\n";
        return;
        p_print("empty");
    }
    if(P->degree == 0){
        std::cout << P->coef;
    }
    else{
        if(P->coef == 1) std::cout << pol_v << '^' << P->degree;
        else if(P->coef == -1) std::cout << '-'<< pol_v << '^' << P->degree;
        else std::cout << P->coef << pol_v << '^' << P->degree;
    }
    P = P->next;
    while(P != nullptr){
        if(P->coef >= 0) std::cout << '+';
        if(P->degree == 0){
            std::cout << P->coef;
            P = P->next;
            continue;
        }
        if(P->coef == 1) std::cout << pol_v << '^' << P->degree;
        else if(P->coef == -1) std::cout << '-'<< pol_v << '^' << P->degree;
        else std::cout << P->coef << pol_v << '^' << P->degree;
        P = P->next;
    }
    std::cout << '\n';
}

void pol_clean_zeros(pol *&P){
    if(P == nullptr) return;
    if(P->coef == 0) {
        pol_delete_el(P);
        pol_clean_zeros(P);
        return;
    }
    pol_clean_zeros(P->next);
    return;
}

void pol_delete_el(pol *&P){
    pol *t = P;
    P = P->next;
    delete t;
}

pol*& pol_inversor(pol *P){
    pol *t1 = new pol;
    pol *&t2 = t1->next;
    t1->next = nullptr;
    while(P != nullptr){
        pol *t = new pol;
        t->next = nullptr;
        t->degree = P->degree;
        t->coef = -P->coef;
        t1->next = t;
        t1 = t1->next;
        P = P->next;
    }
    return t2;
}

pol*& pol_clone(pol *P){
    pol *t = new pol;
    t->next = nullptr;
    while (P != nullptr) {
        pol_append(t->next , P->coef , P->degree);
        P = P->next;
    }
    pol *&t1 = t->next;
    return t1;
}

// pol funtions end
// pol_container functions begin

void pol_cont_renum(){
    pol_cont *t = all_pols;
    int N = 1;
    while(t != nullptr){
        t->N = N;
        t = t->next;
        N++;
    }
    return;
}

void pol_cont_remove_el(pol_cont *&PC , int N){
    if(N == -1 && PC == nullptr) return;
    if(PC == nullptr) throw std::string("pol_cont_remove_el: N out of range");
    if(N == -1){
        pol_cont *t = PC;
        PC = PC->next;
        delete t;
        pol_cont_renum();
        pol_cont_remove_el(PC , N);
        return;
    }
    if(PC->N != N) {
        pol_cont_remove_el(PC->next , N);
        return;
    }
    pol_cont *t = PC;
    PC = PC->next;
    delete t;
    pol_cont_renum();
    return;
}

void pol_cont_add_el(pol *P , int N){
    pol_cont *t1 = all_pols;
    if(t1 == nullptr && !(N == -1 || N == 1)){
        throw std::string("pol_cont_add_el: wrong N");
        return;
    }
    if(t1 == nullptr){
        pol_cont *t = new pol_cont;
        t->next = nullptr;
        t->i_pol = P;
        t->N = 1;
        all_pols = t;
        return;
    }
    if(N == 1){
        pol_cont *t = new pol_cont;
        t->next = all_pols;
        t->i_pol = P;
        t->N = 1;
        all_pols = t;
        return;
    }
    while(N != 2 && t1->next){
        N--;
        t1 = t1->next;
    }
    if(N != 2 && N > -1){
        throw std::string("pol_cont_add_el: wrong N");
        return;
    }
    pol_cont *t = new pol_cont;
    t->next = t1->next;
    t->i_pol = P;
    t->N = 1;
    t1->next = t;
    return;
}

void pol_cont_print_con(){
    pol_cont *t = all_pols;
    if(t == nullptr) std::cout << "1. 0\n";
    while(t != nullptr) {
        std::cout << t->N << ". ";
        pol_printer(t->i_pol);
        t = t->next;
    }
    return;
}

pol*& pol_cont_get_pol(int N){
    if(N == 1){
        return all_pols->i_pol;
    }
    pol_cont *t = all_pols;
    while(N != 2){
        if (t == nullptr){
            throw "error 1";
            exit(0);
        }
        t = t->next;
        N--;
    }
    if(t == nullptr){
        throw "error 1";
        exit(0);
    }
    return t->next->i_pol;
}

// pol_container functions end
