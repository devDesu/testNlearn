#ifndef TASK_14_5_H_INCLUDED
#define TASK_14_5_H_INCLUDED
#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname; // им€ abstr_emp
    std::string lname; // фамили€ abstr_emp
    std::string job;
public:
    abstr_emp(){};
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j): fname(fn), lname(ln), job(j){};
    virtual void ShowAll() const; //выводит все данные с именами
    virtual void SetAll(); //запрашивает значени€ у пользовател€
    friend std::ostream& operator<<(std::ostream & os, const abstr_emp & e); //¬ыводит только им€ и фамилию
    virtual ~abstr_emp() = 0; // виртуальный базовый класс
};
abstr_emp::~abstr_emp(){};

void abstr_emp::ShowAll() const
    {
        std::cout<<"----Abstr emp-----"<<std::endl;
        std::cout<<"Name: "<<fname<<" Surname: "<<lname<<" Job: "<<job<<std::endl;
        std::cout<<"******************"<<std::endl;
    }
void abstr_emp::SetAll()
    {
        using std::cout;
        using std::cin;
        using std::endl;
        cout<<"Enter name: ";
        cin>>fname;
        cout<<"Enter lname: ";
        cin>>lname;
        cout<<"Enter job: ";
        cin>>job;
    }
std::ostream& operator<<(std::ostream & os, const abstr_emp & e) //¬ыводит только им€ и фамилию
    {
        os<<"Name: "<<e.fname<<" Surname: "<<e.lname;
        return os;
    }
class employee : public abstr_emp
{
public:
    employee():abstr_emp(){};
    employee(const std::string & fn, const std::string & ln,
             const std::string & j): abstr_emp(fn, ln, j){};
    virtual void ShowAll() const;
    virtual void SetAll();
};
void employee::ShowAll() const
    {
        std::cout<<"-----Employee-----"<<std::endl;
        abstr_emp::ShowAll();
        std::cout<<"------------------"<<std::endl;
    }
void employee::SetAll(){
        abstr_emp::SetAll();
    }
class manager: virtual public abstr_emp
{
private:
    int inchargeof; // количество управл€емых abstr_emp
protected:
    int InChargeOf() const
    {
        return inchargeof;    // вывод
    }
    int & InChargeOf()
    {
        return inchargeof;    // ввод
    }
public:
    manager():abstr_emp(){};
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0):abstr_emp(fn, ln, j), inchargeof(ico){};
    manager(const abstr_emp& e, int ico):abstr_emp(e), inchargeof(ico){};
    manager(const manager & m):abstr_emp(m), inchargeof(m.inchargeof){};
    virtual void ShowAll() const;
    virtual void SetAll();
};
void manager::ShowAll() const{
        std::cout<<"------Manager-----"<<std::endl;
        abstr_emp::ShowAll();
        std::cout<<" In charge of "<<inchargeof<<std::endl;
        std::cout<<"------------------"<<std::endl;
    }
void manager::SetAll()
    {
        abstr_emp::SetAll();
        std::cout<<"Enter in charge of: ";
        std::cin>>inchargeof;
    }
class fink: virtual public abstr_emp
{
private:
    std::string reportsto; // кому выводить отчеты
protected:
    const std::string ReportsTo() const
    {
        return reportsto;
    }
    std::string & ReportsTo()
    {
        return reportsto;
    }
public:
    fink():abstr_emp(){};
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo):abstr_emp(fn, ln, j), reportsto(rpo){};
    fink(const abstr_emp & e, const std::string & rpo):abstr_emp(e), reportsto(rpo){};
    fink(const fink & e):abstr_emp(e), reportsto(e.reportsto){};
    virtual void ShowAll() const;
    virtual void SetAll();
};
void fink::ShowAll() const
    {
        std::cout<<"-------Fink-------"<<std::endl;
        abstr_emp::ShowAll();
        std::cout<<" Reports to: "<<reportsto<<std::endl;
        std::cout<<"------------------"<<std::endl;
    }
void fink::SetAll()
    {
        abstr_emp::SetAll();
        std::cout<<" Enter reports to: ";
        std::cin>>reportsto;
        //std::cout<<std::endl;
    }
class highfink: public manager, public fink // надзор за управл€ющими
{
public:
    highfink ():abstr_emp(), manager(), fink(){};
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico):abstr_emp(fn, ln, j), manager(*this, ico), fink(*this, rpo){};
    highfink(const abstr_emp & e, const std::string & rpo, int ico):abstr_emp(e), manager(e, ico), fink(e, rpo){};
    highfink(const fink & f, int ico):abstr_emp(f), manager(f, ico), fink(f){};
    highfink(const manager & m, const std::string & rpo):abstr_emp(m), manager(m), fink(*this, rpo){};
    highfink(const highfink & h):abstr_emp(h), manager(h), fink(h){};
    virtual void ShowAll() const;
    virtual void SetAll();
};
void highfink::ShowAll() const
    {
        std::cout<<"-----High Fink----"<<std::endl;
        abstr_emp::ShowAll();
        std::cout<<" Reports to: "<<ReportsTo();
        std::cout<<" In charge of: "<<InChargeOf();
        std::cout<<std::endl;
        std::cout<<"------------------"<<std::endl;
    }
void highfink::SetAll()
    {
        using std::cout;
        using std::endl;
        using std::cin;
        abstr_emp::SetAll();
        cout<<"Enter in charge of: ";
        cin>>InChargeOf();
        cout<<"Enter reports to: ";
        cin>>ReportsTo();
    }
void test145()
{
    using std::cout;
    using std::endl;
    using std::cin;
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    cout<<endl;
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll ();
    fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // укомплектовано?
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
// Ќажать любую клавишу дл€ следующей фазы
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
// »спользование указател€ abstr_emp *
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
}
#endif // TASK_14_5_H_INCLUDED
