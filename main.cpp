#include <iostream>
#include <vector>
#include <numeric>

class Student
{
private:
    std::string name_;
    std::string surname_;
    std::vector<float> grades;
    int album_number_;
public:

    void set_name(std::string n)
    {
        name_ = n;
    }

    std::string get_name()
    {
        return name_;
    }

    void set_surname(std::string s)
    {
        surname_ = s;
    }

    void set_album_number(int albnum)
    {
        if (albnum >= 10000 && albnum <= 999999)
        {
            album_number_ = albnum;
        }
    }

    Student(std::string n = "No", std::string s = "One", std::vector<float> g = {})
    {
        name_ = n;
        surname_ = s;
        for(auto &it : g)
        {
            add_grade(it);
        }
    }

    float calculate_grade()
    {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void print()
    {
        std::cout << name_ << ' ' << surname_ << ": ";
        for(auto &it : grades)
        {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    bool add_grade(float grade)
    {
        if (grade >= 2.0 && grade <= 5.0)
        {
            // The grade is valid; let's add it and return true
            grades.push_back(grade);
            return true;
        }
        // The grade is invalid; let's return false
        return false;
    }

    bool did_pass()
    {
        bool one2_spotted = false;
        for(auto &it : grades)
        {
            if(it == 2)
            {
                if(one2_spotted == true)
                {
                    return false;
                }
                else
                {
                    one2_spotted = true;
                }
            }
        }
        return true;
    }
};

class Complex
{
private:
    float re_;
    float im_;
public:
    Complex(float re, float im = 0)
    {
        re_ = re;
        im_ = im;
    }

    void set_im(float im)
    {
        im_ = im;
    }

    float get_im()
    {
        return im_;
    }

    void set_re(float re)
    {
        re_ = re;
    }

    float get_re()
    {
        return re_;
    }

    void print()
    {
        if(re_ or im_ == 0)
        {
            std::cout << re_;
        }
        if(im_ != 0)
        {
            if(im_ > 0 && re_ != 0)
            {
                std::cout << '+' << im_ << 'i';
            }
            else
            {
                std::cout << im_ << 'i';
            }
        }
        std::cout << '\n';
    }

    Complex add(Complex &b)
    {
        Complex c(0);
        c.re_ = re_ + b.re_;
        c.im_ = im_ + b.im_;
        return c;
    }
};


int main()
{
//    Student student{"Some", "Student", {2, 3, 4, 5, 3}}; // This creates object of Student type
//    std::cout << student.calculate_grade() << std::endl; // This calls calculate_grade function and prints the result
//    student.print();

//    student.grades.push_back(8.0);
//    Student student2{"Jan", "Kowalski", {5, 10, 15}};
//    student2.print();

//    Student s1("Jan", "Feb");
//    s1.print();

//    Student s2;
//    s2.print();

//    Student student{"Some", "Student", {2, 3, 4, 5, 3}}; // This creates object of Student type
//    std::cout << student.calculate_grade() << std::endl; // This calls calculate_grade function and prints the result
//    student.print();
//    student.add_grade(4);
//    student.add_grade(8);
//    student.set_name("Henry");
//    student.print();
//    std::cout << student.get_name() << '\n';
//    std::cout << student.did_pass() << '\n';

    // Final Assignment 2
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

//    std::cout << c.get_re() << c.get_im() << '\n';

    c.print(); // prints 4.14-7i

    return 0;
}
