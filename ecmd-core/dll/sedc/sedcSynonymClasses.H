//IBM_PROLOG_BEGIN_TAG
//IBM_PROLOG_END_TAG

#ifndef sedcSynonymClasses_h
#define sedcSynonymClasses_h

// Class Description *************************************************
//                                                                      
//  Name:  sedcSynonymClasses
//  Base class: 
//
//  Description: 
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include <list>
#include <string>
#include <vector>


//--------------------------------------------------------------------
//  Forward References                                                
//--------------------------------------------------------------------

class sedcSynonymLine
{
   public:
     // Constructors
     inline sedcSynonymLine():
     state(0x0)
     {};

     // Destructor
     virtual inline ~sedcSynonymLine() {};


     // Operators
     int operator=(const sedcSynonymLine &rhs);  ///< Used for copy
     sedcSynonymLine(const sedcSynonymLine &rhs);  ///< Used for copy

     // Other functions
     void reset(); ///< Resets all the variables to they state they were in the constructor

  public:  // Data
    unsigned int state;      ///< Contains information about what states are on
    std::string   lineName;   ///< The spy we want this synonym to go look for - if any one this line
    std::string   lineExtras; ///< Contains any comments that might be on the line as well

  private:  // functions

  private:  // Data

};


class sedcSynonymEntry
{
   public:
     // Constructors
     inline sedcSynonymEntry():
     valid(false)
     {};

     // Destructor
     virtual inline ~sedcSynonymEntry() {};


     // Operators
     int operator=(const sedcSynonymEntry &rhs);  ///< Used for copy
     sedcSynonymEntry(const sedcSynonymEntry &rhs);  ///< Used for copy

  public:  // Data
    bool          valid;     ///< Indicates if the synonym read from the file has valid syntax
    std::string   name;          ///< String name of the entry we are
    std::string   realName;      ///< String name of the spy we should then go look for
    std::list<sedcSynonymLine> synonymLines;   ///< Any comments that might need to be saved away

  private:  // functions

  private:  // Data

};


#endif /* sedcSynonymClasses_h */