#include <iostream>
#include <string>


std::string flag_r(std::string input){
    int n = input.length();
     
    for (int i = 0; i < n / 2; i++)
    {
        std::swap(input[i], input[n - i - 1]);
    }
    return input;
}
    void flag_l(std::string input){
    int n = input.length();
    
    for(int i = 0; i <= n; i++)
    {
        std::cout<<input[i]<<"\n";
    }
}



int main(){
    int index;
    bool r,l,n = false;
    std::string input;
    std::getline(std::cin,input);
    
    if(input.find("-n")!= std::string::npos)
    {
        n = true;
        index = input.find("-n ");
        input.replace(index,3,"");
    }
    if (input.find("-r")!= std::string::npos)
    {
        r = true;
        index = input.find("-r ");
        input.replace(index,3,"");
    }
    if (input.find("-l")!= std::string::npos)
    {
        l = true;
        index = input.find("-l ");
        input.replace(index,3,"");
    }
    
    if(r == true && l == true)
    {
        input = flag_r(input);
        flag_l(input);
    }
    else if (n == true && r ==true)
    {
        input = flag_r(input);
        std::cout<<input;
    }
    else if(n == true)
    {
        std::cout << input;
    }
    else if(r == true)
    {
        input = flag_r(input);
        std::cout << input <<"\n";
    }
    else if(l == true)
    {
        flag_l(input);
    }
   
    
    
    
    
    
    
}

