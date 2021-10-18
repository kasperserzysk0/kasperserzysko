#include <iostream>
#include <vector>
#include <algorithm>



int find_index(std::vector<std::string> v, std::string a)
{
    auto it = std::find(v.begin(), v.end(), a);
    int index;
    
    if (it != v.end())
    {
        index = it - v.begin();
    }
    else
    {
        index = -1;
    }
    return index;
}



int main(int argc, char * argv[])
{
    bool r,l,n = false;
    std::vector<std::string> args = std::vector<std::string>(argv+1, argv + argc);
    
    //FLAGS
    if(find_index(args, "-r")!= -1)
    {
        args.erase(args.begin()+find_index(args,"-r"));
        r = true;
    }
    if(find_index(args, "-l")!= -1)
    {
        args.erase(args.begin()+find_index(args,"-l"));
        l = true;
    }
    if(find_index(args, "-n")!= -1)
    {
        args.erase(args.begin()+find_index(args,"-n"));
        n = true;
    }
    
    //OUTPUT
    if (r == true && l == true)
    {
        std::reverse(args.begin(),args.end());
        for(std::string a:args)
        {
            std::cout <<a<<"\n";
        }
    }
   else if(r == true && n == true)
   {
       std::reverse(args.begin(),args.end());
       for(std::string a:args)
       {
           std::cout <<a<<" ";
       }
   }
    else if (r == true)
    {
        std::reverse(args.begin(),args.end());
        for(std::string a:args)
        {
            std::cout <<a<<" ";
        }
    }
    else if (l == true)
    {
        for(std::string a:args)
        {
            std::cout <<a<<"\n";
        }
    }
    else if (n == true)
    {
        for(std::string a:args)
        {
            std::cout <<a<<" ";
        }
    }
   
    

    

return 0;
}
