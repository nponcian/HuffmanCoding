/*
This code is not for the faint-hearted! If you have history of medical illnesses, I suggest you to
close this file NOW URGENTLY!!! Reading this piece of code is too dangerous for your,... eyes!

I wrote this code back in January 27, 2013, 14:14:53 as a challenge to myself during my college years.
While I was doing an assignment for one of my subjects with the goal of compressing a list of texts
by using Huffman Coding, I realized that such manual derivation of the Huffman codes are too prone
to human error. Using an online calculator would be okay, but I then felt it was boring after EXCITEMENT
exploded within my mind upon thinking about writing a program OF MY OWN that would verify all my answers.
Whoa! That is totally possible! The major challenge to me back then was how do I implement the concept
of implementing a tree. My innocent 2013 mind unfortunately wasn't able to think that doing a struct Node*
with details of the left and right would be the way to go, but never underestimate the power of that
innocent 2013 mind! As the idea of grouping characters into parenthesis such that in (ab) the "a" would
be the "left node" while "b" would be the "right node" suddenly struck me back then and I realize that
it is totally DOABLE!!! I enjoyed it. I was really proud back then!

But fast forward, 2019, I am now ashamed of this whole garbage code ^_^

This code is totally ugly, unreadable, unmaintainable, cannot be extended easily, undivided functionalities
and was just put to a single block of code, duplicate codes all over the place, naming conventions are
so bad, chosen data types are also so bad, signed and unsigned comparisons was all over the place originally,
and the whole code itself just looks like a big mess!

BUT IT WORKED! With a really really poor quality!

I have tried as much as possible to preserve the authenticity of this whole algorithm in this file
and thus not made any relevant changes. This would serve as a part of my history as a programmer. :)
*/

#include <Algorithm/ParenthesisStringAlgorithm_DirtyVersion.hpp>

#include<string.h>

#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

common::Logger logger("ParenthesisStringAlgorithm_DirtyVersion");

// Unless you want this garbage code to randomly produce different results given the same input,
// put the declaration here globally for it to be initialized. As putting it below inside the scope
// of compress method puts it into stack uninitialized.
    int ctr,ctr2,num,loop1,loop2,loop3,templen,pangilan[99],len1[99],len2[99];
    char tempstr,tempstr2[99],str1[99],str2[99],str3[99][99],code[99][99];

} // namespace

ParenthesisStringAlgorithm_DirtyVersion::ParenthesisStringAlgorithm_DirtyVersion()
{
}

CharacterAndCodeMap ParenthesisStringAlgorithm_DirtyVersion::compress(const std::string& text)
{
    logger.print("Executing algorithm without formatting of logger prints...");
    // cout<<"Enter string: ";
    // gets(str1);
    for (unsigned ctr = 0; ctr < text.size() && ctr < 99; ctr++)
    {
        str1[ctr] = text.at(ctr);
    }
    
    for(loop1=0; (unsigned)loop1<strlen(str1); loop1++)
    {
        if(str1[loop1]>=65 && str1[loop1]<=90)
            str1[loop1]=str1[loop1]+32; // or simply: tolower(str1[loop1]);
        //since these three characters will be used as indicators inside the program, replace them first by other characters
        else if(str1[loop1]=='(')
            str1[loop1]=8;
        else if(str1[loop1]==')')
            str1[loop1]=24;
        else if(str1[loop1]=='`')
            str1[loop1]=27;
    }
    
    for(loop1=0,loop3=0; (unsigned)loop1<text.size(); loop1++) // counts the number of frequencies of each character (note: this part removes -> ( ) ` -> these characters are used as indicators: () to indicate the code (ung 0 or 1, 0 pag left 1 pag right) then ung ` is ung special character na ginawa ring indicator for... XD
    {
        if(str1[loop1]=='`')
            continue;
        for(loop2=loop1+1,len1[loop1]=1; (unsigned)loop2<strlen(str1); loop2++)
        {
            if(str1[loop1]==str1[loop2])
            {
                len1[loop1]++;
                str1[loop2]='`';
            }
        }
        str2[loop3]=str1[loop1];
        len2[loop3]=len1[loop1];
        pangilan[loop3]=loop3;
        loop3++;
    }
    
    logger.printNoFormatting("\nCharacter\t\tFrequency"); // display list not sorted
    for(loop1=0; loop1<loop3; loop1++)
    {
        if(str2[loop1]==8) 
            logger.printNoFormatting("\n(");
        else if(str2[loop1]==24)
            logger.printNoFormatting("\n)");
        else if(str2[loop1]==27)
            logger.printNoFormatting("\n`");
        else
            logger.printNoFormatting("\n",str2[loop1]);
        logger.printNoFormatting("\t\t\t",len2[loop1]);
    }
    
    // sort by increasing frequency
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) 
        {
            if(len2[loop1]>len2[loop2])
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }
    }
    // sort by character, for those with same frequencies, letters first before special characters
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) // pag may pareparehas na frequency, iarrange according to ASCII code (ex. o->2  "->2  p->2) o=111  "=34  p=112  --> so dapat mauna ung pinakamataas na value: p, then o, then " 
        {
            if( len2[loop1]==len2[loop2] && (str2[loop1]<97 || str2[loop1]>122) && (str2[loop2]>=97 && str2[loop2]<=122) )
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }   
    }
    // sort by order in the string entered for those letters with same frequencies and for those special characters with same frequencies
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) 
        {
            if( len2[loop1]==len2[loop2] && (((str2[loop1]>=97 && str2[loop1]<=122) && (str2[loop2]>=97 && str2[loop2]<=122) && pangilan[loop1]>pangilan[loop2])  || ((str2[loop1]<97 || str2[loop1]>122) && (str2[loop2]<97 || str2[loop2]>122) && pangilan[loop1]>pangilan[loop2])) )
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }   
    }
    
    logger.printNoFormatting("\n\nCharacter\t\tFrequency"); // display list sorted
    for(loop1=0; loop1<loop3; loop1++)
    {
        if(str2[loop1]==8) 
            logger.printNoFormatting("\n(");
        else if(str2[loop1]==24)
            logger.printNoFormatting("\n)");
        else if(str2[loop1]==27)
            logger.printNoFormatting("\n`");
        else
            logger.printNoFormatting("\n",str2[loop1]);
        logger.printNoFormatting("\t\t\t",len2[loop1]);
    }
   
    for(loop1=0; loop1<loop3; loop1++) // solve list sorted increasing frequency
        str3[loop1][0]=str2[loop1]; // linagay sya sa string array para pede magconcatenate (magkaroon ng more than one character
    
    for(; loop3-1>0; loop3--) // solve list sorted increasing frequency
    {
        strcpy( str3[0],strcat(str3[0],str3[1]) ); // icocombine nya ung 1st and 2nd element
        len2[0]=len2[0]+len2[1];
        
        strcpy(str3[0],strcat(strcat(strcpy(tempstr2,"("),str3[0]),")")); // ieenclose ung isang part by parentheses para magroup ex. r and ! -> (r!) -> r! and p -> ((r!)p)
        
        for(loop1=1; loop1<loop3-1; loop1++) //ishishift to the left ung mga value
        {
            strcpy(str3[loop1],str3[loop1+1]);
            len2[loop1]=len2[loop1+1];
        }
      
        for(loop1=0; loop1<loop3-1; loop1++) // isosort increasing frequency
        {
            for(loop2=loop1; loop2<loop3-1; loop2++)
            {
                if(len2[loop1]>len2[loop2])
                {
                    templen=len2[loop1];
                    len2[loop1]=len2[loop2];
                    len2[loop2]=templen;
                
                    templen=pangilan[loop1];
                    pangilan[loop1]=pangilan[loop2];
                    pangilan[loop2]=templen;
                
                    strcpy(tempstr2,str3[loop1]);
                    strcpy(str3[loop1],str3[loop2]);
                    strcpy(str3[loop2],tempstr2);
                }
            }
        }

        logger.printNoFormatting("\n\nCharacter\t\tFrequency"); //ididisplay na ung result after isort every step
        for(loop1=0; loop1<loop3-1; loop1++)
        {
            logger.printNoFormatting("\n");
            for(loop2=0; (unsigned)loop2<strlen(str3[loop1]); loop2++)
            {
                if(str3[loop1][loop2]==8) 
                    logger.printNoFormatting("(");
                else if(str3[loop1][loop2]==24)
                    logger.printNoFormatting(")");
                else if(str3[loop1][loop2]==27)
                    logger.printNoFormatting("`");
                else
                    logger.printNoFormatting(str3[loop1][loop2]);
            }
            logger.printNoFormatting("\t\t\t",len2[loop1]);
        }
    }

    strcpy(str3[0],strcat(strcat(strcpy(tempstr2,"`"),str3[0]),"`")); // indicator na pag may space, un na ung end ng string (either start or end)
    strcpy(tempstr2,str3[0]);
    
    for(loop1=1; (unsigned)loop1<strlen(str3[0])-1; loop1++)
    {
        if(str3[0][loop1]=='(' || str3[0][loop1]==')')
            continue;
        for(loop3=loop1; ; )
        {
            if(str3[0][loop3-1]=='(') // pag ang katabi sa left is ( ibig sabihin nun is 0 ex. (r !) --> r is 0, ! is 1
            {
                strcat(code[loop1],"0"); // since ang katabi sa left is ( magaadd sya ng 0 dun sa code
                for(ctr=0,num=0; ; ctr++) // hahanaping ung ( then bibilangin kung ilang characters bago un
                {
                    if(str3[0][loop3-ctr]==')')
                        num--;
                    else if(str3[0][loop3-ctr]=='(')
                        num++;
                    if(num==1)
                        break;
                }
                for(ctr2=0,num=0; ; ctr2++) // hahanaping ung ) then bibilangin kung ilang characters bago un
                {
                    if(str3[0][loop3+ctr2]=='(')
                        num--;
                    else if(str3[0][loop3+ctr2]==')')
                        num++;
                    if(num==1)
                        break;
                }
                str3[0][loop3-ctr]='`'; // gagawin nyang ` ung part (particularly ung "(") pag alam na kung ano dun ung 0 and 1 --> ex. (b(o")) -> o is 0, " is 1 -> then, gagawin na yang: (b ) -> the equivalent of space is (o") -> para gawin un, ginawang space ung '(' then inurong ung mga value to the left para matakpan ung 'o")'
                for(loop2=loop3-ctr+1; (unsigned)loop2<strlen(str3[0]); loop2++)
                    str3[0][loop2]=str3[0][loop2+ctr+ctr2]; // inurong ung value to the left, ung number of shift is depende dun sa distance nung open '('  dun sa pang close ')' --> ex. (((r!)p)e) -> (alam mo na na (r!) is 0 and p is 1), sa p:  -> gawing space ung 5th (5 is the space from p to '(' -> note: ndi yan ung unang naencounter nya na '(' kasi ung una is para sa (r!) at ndi para sa ((r!)p) ) then: ( (r!)p)e) then shift 6 (ung ung distance of p from '(' plus ung distance of p from ')' -> 5+1=6) then -> ( e) where ung equivalent ng space is ((r!)p)
                loop3=loop3-ctr; //pupunta ung loop sa ` which is ung part na alam mo na kung 0 (left) or 1 (right)
            }
            else if(str3[0][loop3+1]==')') // pag ang katabi sa right is ) ibig sabihin nun is 1 ex. (r !) --> r is 0, ! is 1
            {
                strcat(code[loop1],"1"); // since ang katabi sa right is ) magaadd sya ng 1 dun sa code
                for(ctr=0,num=0; ; ctr++)
                {
                    if(str3[0][loop3-ctr]==')')
                        num--;
                    else if(str3[0][loop3-ctr]=='(')
                        num++;
                    if(num==1)
                        break;
                }
                for(ctr2=0,num=0; ; ctr2++)
                {
                    if(str3[0][loop3+ctr2]=='(')
                        num--;
                    else if(str3[0][loop3+ctr2]==')')
                        num++;
                    if(num==1)
                        break;
                }
                str3[0][loop3-ctr]='`';
                for(loop2=loop3-ctr+1; (unsigned)loop2<strlen(str3[0]); loop2++)
                    str3[0][loop2]=str3[0][loop2+ctr+ctr2];
                loop3=loop3-ctr;
            }
            if(str3[0][loop3-1]=='`' || str3[0][loop3+1]=='`') // pag ` na ung next(either sa left->start or right->end) un na ung end ng string 
                break;
        }
        strcpy(str3[0],tempstr2);
    }
    
    logger.printNoFormatting("\n\nCharacter\t\tCode");
    for(loop1=0; (unsigned)loop1<strlen(str3[0]); loop1++)
    {
        if(str3[0][loop1]=='(' || str3[0][loop1]==')' || str3[0][loop1]=='`')
            continue;
        if(str3[0][loop1]==8) 
            logger.printNoFormatting("\n(\t\t\t");
        else if(str3[0][loop1]==24)
            logger.printNoFormatting("\n)\t\t\t");
        else if(str3[0][loop1]==27)
            logger.printNoFormatting("\n`\t\t\t");
        else
            logger.printNoFormatting("\n",str3[0][loop1],"\t\t\t");
        for(loop2=strlen(code[loop1])-1; loop2>=0; loop2--)
            logger.printNoFormatting(code[loop1][loop2]);
    }
    
    logger.printNoFormatting("\n\n\n\nProgram by PONci (circa 2013)\n");
    logger.printNoFormatting("|------    ---------     |\\      |\n");
    logger.printNoFormatting("|      |  |         |    | \\     |\n");  
    logger.printNoFormatting("|      |  |  O  --  |    |  \\    |\n");  
    logger.printNoFormatting("|------   |         |    |   \\   |\n");
    logger.printNoFormatting("|         |  \\___/  |    |    \\  |\n");
    logger.printNoFormatting("|          ---------     |     \\ |\n");
    logger.printNoFormatting("|                        |      \\|\n\n"); 
    // getch();

    logger.print("Execution of algorithm finished");
    return {};
}

} // src::algo

/*

// This is the raw version of the whole code written on January 27, 2013, 14:14:53
// File is in Operating System\Lec\Huffman Coding

#include<iostream.h>
#include<string.h>
#include<conio.h>

    int ctr,ctr2,num,loop1,loop2,loop3,templen,pangilan[99],len1[99],len2[99];
    char tempstr,tempstr2[99],str1[99],str2[99],str3[99][99],code[99][99];
    
main()
{   
    cout<<"Enter string: ";
    gets(str1);
    
    for(loop1=0; loop1<strlen(str1); loop1++)
    {
        if(str1[loop1]>=65 && str1[loop1]<=90)
            str1[loop1]=str1[loop1]+32; // or simply: tolower(str1[loop1]);
        //since these three characters will be used as indicators inside the program, replace them first by other characters
        else if(str1[loop1]=='(')
            str1[loop1]=8;
        else if(str1[loop1]==')')
            str1[loop1]=24;
        else if(str1[loop1]=='`')
            str1[loop1]=27;
    }
    
    for(loop1=0,loop3=0; loop1<strlen(str1); loop1++) // counts the number of frequencies of each character (note: this part removes -> ( ) ` -> these characters are used as indicators: () to indicate the code (ung 0 or 1, 0 pag left 1 pag right) then ung ` is ung special character na ginawa ring indicator for... XD
    {
        if(str1[loop1]=='`')
            continue;
        for(loop2=loop1+1,len1[loop1]=1; loop2<strlen(str1); loop2++)
        {
            if(str1[loop1]==str1[loop2])
            {
                len1[loop1]++;
                str1[loop2]='`';
            }
        }
        str2[loop3]=str1[loop1];
        len2[loop3]=len1[loop1];
        pangilan[loop3]=loop3;
        loop3++;
    }
    
    cout<<"\nCharacter\t\tFrequency"; // display list not sorted
    for(loop1=0; loop1<loop3; loop1++)
    {
        if(str2[loop1]==8) 
            cout<<"\n(";
        else if(str2[loop1]==24)
            cout<<"\n)";
        else if(str2[loop1]==27)
            cout<<"\n`";
        else
            cout<<"\n"<<str2[loop1];
        cout<<"\t\t\t"<<len2[loop1];
    }
    
    // sort by increasing frequency
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) 
        {
            if(len2[loop1]>len2[loop2])
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }
    }
    // sort by character, for those with same frequencies, letters first before special characters
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) // pag may pareparehas na frequency, iarrange according to ASCII code (ex. o->2  "->2  p->2) o=111  "=34  p=112  --> so dapat mauna ung pinakamataas na value: p, then o, then " 
        {
            if( len2[loop1]==len2[loop2] && (str2[loop1]<97 || str2[loop1]>122) && (str2[loop2]>=97 && str2[loop2]<=122) )
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }   
    }
    // sort by order in the string entered for those letters with same frequencies and for those special characters with same frequencies
    for(loop1=0; loop1<loop3; loop1++)
    {
        for(loop2=loop1; loop2<loop3; loop2++) 
        {
            if( len2[loop1]==len2[loop2] && (((str2[loop1]>=97 && str2[loop1]<=122) && (str2[loop2]>=97 && str2[loop2]<=122) && pangilan[loop1]>pangilan[loop2])  || ((str2[loop1]<97 || str2[loop1]>122) && (str2[loop2]<97 || str2[loop2]>122) && pangilan[loop1]>pangilan[loop2])) )
            {
                templen=len2[loop1];
                len2[loop1]=len2[loop2];
                len2[loop2]=templen;
                
                templen=pangilan[loop1];
                pangilan[loop1]=pangilan[loop2];
                pangilan[loop2]=templen;
                
                tempstr=str2[loop1];
                str2[loop1]=str2[loop2];
                str2[loop2]=tempstr;
            }
        }   
    }
    
    cout<<"\n\nCharacter\t\tFrequency"; // display list sorted
    for(loop1=0; loop1<loop3; loop1++)
    {
        if(str2[loop1]==8) 
            cout<<"\n(";
        else if(str2[loop1]==24)
            cout<<"\n)";
        else if(str2[loop1]==27)
            cout<<"\n`";
        else
            cout<<"\n"<<str2[loop1];
        cout<<"\t\t\t"<<len2[loop1];
    }
   
    for(loop1=0; loop1<loop3; loop1++) // solve list sorted increasing frequency
        str3[loop1][0]=str2[loop1]; // linagay sya sa string array para pede magconcatenate (magkaroon ng more than one character
    
    for(; loop3-1>0; loop3--) // solve list sorted increasing frequency
    {
        strcpy( str3[0],strcat(str3[0],str3[1]) ); // icocombine nya ung 1st and 2nd element
        len2[0]=len2[0]+len2[1];
        
        strcpy(str3[0],strcat(strcat(strcpy(tempstr2,"("),str3[0]),")")); // ieenclose ung isang part by parentheses para magroup ex. r and ! -> (r!) -> r! and p -> ((r!)p)
        
        for(loop1=1; loop1<loop3-1; loop1++) //ishishift to the left ung mga value
        {
            strcpy(str3[loop1],str3[loop1+1]);
            len2[loop1]=len2[loop1+1];
        }
      
        for(loop1=0; loop1<loop3-1; loop1++) // isosort increasing frequency
        {
            for(loop2=loop1; loop2<loop3-1; loop2++)
            {
                if(len2[loop1]>len2[loop2])
                {
                    templen=len2[loop1];
                    len2[loop1]=len2[loop2];
                    len2[loop2]=templen;
                
                    templen=pangilan[loop1];
                    pangilan[loop1]=pangilan[loop2];
                    pangilan[loop2]=templen;
                
                    strcpy(tempstr2,str3[loop1]);
                    strcpy(str3[loop1],str3[loop2]);
                    strcpy(str3[loop2],tempstr2);
                }
            }
        }

        cout<<"\n\nCharacter\t\tFrequency"; //ididisplay na ung result after isort every step
        for(loop1=0; loop1<loop3-1; loop1++)
        {
            cout<<"\n";
            for(loop2=0; loop2<strlen(str3[loop1]); loop2++)
            {
                if(str3[loop1][loop2]==8) 
                    cout<<"(";
                else if(str3[loop1][loop2]==24)
                    cout<<")";
                else if(str3[loop1][loop2]==27)
                    cout<<"`";
                else
                    cout<<str3[loop1][loop2];
            }
            cout<<"\t\t\t"<<len2[loop1];
        }
    }

    strcpy(str3[0],strcat(strcat(strcpy(tempstr2,"`"),str3[0]),"`")); // indicator na pag may space, un na ung end ng string (either start or end)
    strcpy(tempstr2,str3[0]);
    
    for(loop1=1; loop1<strlen(str3[0])-1; loop1++)
    {
        if(str3[0][loop1]=='(' || str3[0][loop1]==')')
            continue;
        for(loop3=loop1; ; )
        {
            if(str3[0][loop3-1]=='(') // pag ang katabi sa left is ( ibig sabihin nun is 0 ex. (r !) --> r is 0, ! is 1
            {
                strcat(code[loop1],"0"); // since ang katabi sa left is ( magaadd sya ng 0 dun sa code
                for(ctr=0,num=0; ; ctr++) // hahanaping ung ( then bibilangin kung ilang characters bago un
                {
                    if(str3[0][loop3-ctr]==')')
                        num--;
                    else if(str3[0][loop3-ctr]=='(')
                        num++;
                    if(num==1)
                        break;
                }
                for(ctr2=0,num=0; ; ctr2++) // hahanaping ung ) then bibilangin kung ilang characters bago un
                {
                    if(str3[0][loop3+ctr2]=='(')
                        num--;
                    else if(str3[0][loop3+ctr2]==')')
                        num++;
                    if(num==1)
                        break;
                }
                str3[0][loop3-ctr]='`'; // gagawin nyang ` ung part (particularly ung "(") pag alam na kung ano dun ung 0 and 1 --> ex. (b(o")) -> o is 0, " is 1 -> then, gagawin na yang: (b ) -> the equivalent of space is (o") -> para gawin un, ginawang space ung '(' then inurong ung mga value to the left para matakpan ung 'o")'
                for(loop2=loop3-ctr+1; loop2<strlen(str3[0]); loop2++)
                    str3[0][loop2]=str3[0][loop2+ctr+ctr2]; // inurong ung value to the left, ung number of shift is depende dun sa distance nung open '('  dun sa pang close ')' --> ex. (((r!)p)e) -> (alam mo na na (r!) is 0 and p is 1), sa p:  -> gawing space ung 5th (5 is the space from p to '(' -> note: ndi yan ung unang naencounter nya na '(' kasi ung una is para sa (r!) at ndi para sa ((r!)p) ) then: ( (r!)p)e) then shift 6 (ung ung distance of p from '(' plus ung distance of p from ')' -> 5+1=6) then -> ( e) where ung equivalent ng space is ((r!)p)
                loop3=loop3-ctr; //pupunta ung loop sa ` which is ung part na alam mo na kung 0 (left) or 1 (right)
            }
            else if(str3[0][loop3+1]==')') // pag ang katabi sa right is ) ibig sabihin nun is 1 ex. (r !) --> r is 0, ! is 1
            {
                strcat(code[loop1],"1"); // since ang katabi sa right is ) magaadd sya ng 1 dun sa code
                for(ctr=0,num=0; ; ctr++)
                {
                    if(str3[0][loop3-ctr]==')')
                        num--;
                    else if(str3[0][loop3-ctr]=='(')
                        num++;
                    if(num==1)
                        break;
                }
                for(ctr2=0,num=0; ; ctr2++)
                {
                    if(str3[0][loop3+ctr2]=='(')
                        num--;
                    else if(str3[0][loop3+ctr2]==')')
                        num++;
                    if(num==1)
                        break;
                }
                str3[0][loop3-ctr]='`';
                for(loop2=loop3-ctr+1; loop2<strlen(str3[0]); loop2++)
                    str3[0][loop2]=str3[0][loop2+ctr+ctr2];
                loop3=loop3-ctr;
            }
            if(str3[0][loop3-1]=='`' || str3[0][loop3+1]=='`') // pag ` na ung next(either sa left->start or right->end) un na ung end ng string 
                break;
        }
        strcpy(str3[0],tempstr2);
    }
    
    cout<<"\n\nCharacter\t\tCode";
    for(loop1=0; loop1<strlen(str3[0]); loop1++)
    {
        if(str3[0][loop1]=='(' || str3[0][loop1]==')' || str3[0][loop1]=='`')
            continue;
        if(str3[0][loop1]==8) 
            cout<<"\n(\t\t\t";
        else if(str3[0][loop1]==24)
            cout<<"\n)\t\t\t";
        else if(str3[0][loop1]==27)
            cout<<"\n`\t\t\t";
        else
            cout<<"\n"<<str3[0][loop1]<<"\t\t\t";
        for(loop2=strlen(code[loop1])-1; loop2>=0; loop2--)
            cout<<code[loop1][loop2];
    }
    
    cout<<"\n\n\n\nProgram by PONci\n";
    cout<<"|------    ---------     |\\      |\n";
    cout<<"|      |  |         |    | \\     |\n";  
    cout<<"|      |  |  O  --  |    |  \\    |\n";  
    cout<<"|------   |         |    |   \\   |\n";
    cout<<"|         |  \\___/  |    |    \\  |\n";
    cout<<"|          ---------     |     \\ |\n";
    cout<<"|                        |      \\|\n"; 
    getch();
}

*/
