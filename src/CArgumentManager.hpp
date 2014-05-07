#ifndef _CARGUMENTMANAGER_HPP_
#define _CARGUMENTMANAGER_HPP_

#include<iostream>
#include<vector>
#include<map>

namespace NDormon{
  /**
   * @brief Represents manager of program arguments
   */
  class CArgumentManager
  {
    private:
      std::vector<std::string>ArgList;///<list of program arguments
    public:
      /**
       * @brief Constructor
       *
       * @param Argc   number of arguments
       * @param Argv[] arguments
       */
      CArgumentManager(int Argc,char*Argv[]);
      /**
       * @brief Gets following argument
       *
       * @param ArgName argument name
       * @param Default default returning value if the arg. is not found
       *
       * @return return next argument (1024 for -w; -w 1024)
       */
      std::string GetArg(std::string ArgName,std::string Default="");
      /**
       * @brief Gets following argument in context
       *
       * @param Start starting argument of context
       * @param End ending argument of context
       * @param ArgName argument name
       * @param Default default returning value if the arg. is not found
       *
       * @return 768 for -h in: -foo -tessstart -w 1024 -h 768 -tessend
       */
      std::string GetArg(std::string Start,std::string End,
          std::string ArgName,std::string Default="");
      /**
       * @brief Is argument present
       *
       * @param ArgName argument name
       *
       * @return return true if the argument is used
       */
      bool IsPresent(std::string ArgName);
      /**
       * @brief Is arguemnt present in context
       *
       * @param Start starting argument of context
       * @param End ending argument of context
       * @param ArgName argment name
       *
       * @return true for -h in: -foo -gostart -bla -h -jojo -goend
       */
      bool IsPresent(std::string Start,std::string End,std::string ArgName);
      /**
       * @brief Gets number of arguments in context
       *
       * @param Start starting argument of context
       * @param End ending arguement of context
       *
       * @return 3 in: -foo -blastart -a -b -c -blaend
       */
      unsigned GetContextLenght(std::string Start,std::string End);
      /**
       * @brief Gets argument in context by index
       *
       * @param Start starting argument of context
       * @param End endif argument of context
       * @param Index index of argument in context
       * @param Default default value of argument
       *
       * @return g for 2 in: -foo -hahastart a b g d -hahaend
       */
      std::string GetArg(std::string Start,std::string End,
          unsigned Index,std::string Default="");
  };
}

#endif//_CARGUMENTMANAGER_HPP_
