#include "analyseur.h"
////
typetoken token;
extern int yylex();
extern char* yytext; // it's a solution to get a String as a token 
extern int yylineno;
//
boolean _prove();
boolean _prove_aux();
///
typetoken _lire_token(){
    return (typetoken)yylex();
}
/*
_type := FLOAT | INTEGER | CHAR | STRING | NATURAL
*/
boolean _type(){
    boolean resultat=false;
    if(token==FLOAT){
        resultat=true;
    }
    else if(token==INTEGER){
        resultat=true;
    }
    else if(token==CHAR){
        resultat=true;
    }
    else if(token==STRING){
        resultat=true;
    }
    else if(token==NATURAL){
        resultat=true;
    }
    else resultat=false;
    return resultat;
}
///////////////////////////// _const()
/*
_const := NUM | IDF
*/
boolean _const(){
    boolean resultat=false;
    if(token==NUM){
        resultat=true;
    }
    else if(token==IDF){ // can be used with different ways
        resultat=true;
    }
    else{
        resultat=false;
    }
    return resultat;
}
/////////////////////////////////////// _prove()
/*

_prove:= IDF DEF_TYPE_VAR _type AFFECT _const PT_COMMA
                        | PT_COMMA
            | CONSTANT DEF_TYPE_VAR _type AFFECT _const PT_COMMA
                        | PT_COMMA

*/
boolean _prove(){
    boolean resultat=false;
    // IDF defines a string or a variable 
    if(token==IDF){
        token=_lire_token();
        if(token==DEF_TYPE_VAR){
            token=_lire_token();
            if(_type()){
                token=_lire_token();
                if(token==AFFECT){
                    token=_lire_token();
                    if(_const()){
                        token=_lire_token();
                        if(token==PT_COMMA){
                            resultat=true;
                        }  
                        else resultat=false;
                    }
                    else{
                        resultat=false;
                    }
                }
                else if(token==PT_COMMA){
                    resultat=true;
                }
                else resultat=false;
            }
            // we can put for exp  var : constant Integer :=3;
            else if(token==CONST){
                if(_type()){
                    token=_lire_token();
                    if(token==AFFECT){
                        token=_lire_token();
                        if(_const()){
                            resultat=true;
                        }
                        else{
                            resultat=false;
                        }
                    }
                    else if(token==PT_COMMA){
                        resultat=true;
                    }
                    else resultat=false;
                }
                else{
                    resultat=false;
                }
            }
            else{
                resultat=false;
            }
        }
    }
    else if(token==WITH){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==PT_COMMA){
                resultat=true;
            }
            else if(token==COMMA){
                token=_lire_token();
                if(token==IDF){
                    resultat=true;
                }
                else if(token==COMMA){
                    // dans le cas de plusieurs importations
                }
            }
            else resultat=false;
        }
        else resultat=false;
    }
    else if(token==USE){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==PT_COMMA){
                resultat=true;
            }
            else if(token==COMMA){
                token=_lire_token();
                if(token==IDF){
                    resultat=true;
                }
                else if(token==COMMA){
                    // dans le cas de plusieurs importations
                }
            }
            else resultat=false;
        }
        else resultat=false;
    }
    // this else if , is just for Spark not Ada
    //
    else if(token==PACK){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==WITH){
                token=_lire_token();
                if(token==SPARK_Mode){
                    token=_lire_token();
                    if(token==IS){
                        resultat=true;
                    }
                    else resultat=false;
                }
                else resultat=false;
            }
            /*
            else if(token==IS){
                resultat=true; // c'est juste pour Ada
            }*/
            else resultat=false;
        }
        else resultat=false;
    }
    // this else if is specially for Spark (and specially for the ads file)
    else if(token==TYPE){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==IS){
                token=_lire_token();
                if(token==NEW){
                    token=_lire_token();
                    if(_type()){
                        token=_lire_token();
                        if(token==PT_COMMA){
                            resultat=true;
                        }
                        else{
                            resultat=false;
                        }
                    }
                    else{
                        resultat=false;
                    }
                }
                else if(token==PRIVATE){
                    token=_lire_token();
                    if(token==PT_COMMA){
                        resultat=true;
                    }
                    else{
                        resultat=false;
                    }
                }
                else{
                    resultat=false;
                }
            }
            else{
                resultat=false;
            }
        }
        else{
            resultat=false;
        }
    }
    //this "else if" is specially for Spark ads file
    else if(token==FUNC){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==RETURN){
                token=_lire_token();
                if(token==IDF){
                    token=_lire_token();
                    if(token==PT_COMMA){
                        resultat=true;
                    }
                    else{
                        resultat=false;
                    }
                }
                else{
                    resultat=false;
                }
            }
            else if(token==POPEN){
                token=_lire_token();
                if(token==IDF){
                    token=_lire_token();
                    if(token==DEF_TYPE_VAR){
                        token=_lire_token();
                        if(token==IN){
                            token=_lire_token();
                            if(token==IDF){
                                token=_lire_token();
                                if(token==PCLOSE){
                                    token=_lire_token();
                                    if(token==RETURN){
                                        token=_lire_token();
                                        if(token==IDF){
                                            token=_lire_token();
                                            if(token==PT_COMMA){
                                                resultat=true;
                                            }
                                            else{
                                                resultat=false;
                                            }
                                        }
                                        else{
                                            resultat=false;
                                        }
                                    }
                                    else{
                                        resultat=false;
                                    }
                                }
                                else{
                                    resultat=false;
                                }
                            }
                            else if(token==OUT){
                                // erreur sémantique de GNATProve
                                printf("A semantic error : It's against Gnatprove rules at line %d\n",yylineno);resultat=true;
                            }
                            else{
                                resultat=false;
                            }
                        }
                        else if(token==OUT){
                            // erreur sémantique de GNATProve
                            printf("A semantic error : It's against Gnatprove rules at line %d\n",yylineno);resultat=true;
                        }
                        else{
                            resultat=false;
                        }
                    }
                    else{
                        resultat=false;
                    }
                }
            }
            else{
                resultat=false;
            }
        }
        else{
            resultat=false;
        }
    }
    // this else if also is specially for "ads" file
    else if(token==PROC){
        token=_lire_token();
        if(token==IDF){
            token=_lire_token();
            if(token==POPEN){
                token=_lire_token();
                if(token==IDF){
                    token=_lire_token();
                    if(token==DEF_TYPE_VAR){
                        token=_lire_token();
                        if(token==IN){
                            token=_lire_token();
                            if(token==IDF){
                                token=_lire_token();
                                if(token==PT_COMMA){
                                    token=_lire_token();
                                    if(token==IDF){
                                        token=_lire_token();
                                        if(token==DEF_TYPE_VAR){
                                            token=_lire_token();
                                            if(token==IDF){
                                                token=_lire_token();
                                                if(token==PCLOSE){
                                                    token=_lire_token();
                                                    if(token==PT_COMMA){
                                                        resultat=true;
                                                    }
                                                    else{
                                                        resultat=false;
                                                    }
                                                }
                                                else{
                                                    resultat=false;
                                                }
                                            }
                                            else{
                                                    resultat=false;
                                            }
                                        }
                                        else{
                                            resultat=false;
                                        }
                                    }
                                    else{
                                        resultat=false;
                                    }
                                }
                                else{
                                    resultat=false;
                                }
                            }
                            else if(token==OUT){
                                // erreur sémantique de GNATProve
                                printf("A semantic error : It's against Gnatprove rules at line %d\n",yylineno);resultat=true;
                            }
                            else{
                                resultat=false;
                            }
                        }
                        else if(token==OUT){
                            // erreur sémantique de GNATProve
                            printf("A semantic error : It's against Gnatprove rules at line %d\n",yylineno);resultat=true;
                        }
                        else{
                            resultat=false;
                        }
                    }
                    else{
                        resultat=false;
                    }
                }
                else{
                    resultat=false;
                }
            }
            else{
                resultat=false;
            }
        }
        else{
            resultat=false;
        }
    }
    else resultat=false;
    return resultat;
}
////////////////////////////////////// _prove_aux() not used yet, or let's say it's not needed no more
boolean _prove_aux(){
    boolean resultat=false;
    if(token==BEG_IN){
        resultat=true;
        printf("it's begin\n");
    }
    else{
        resultat=_prove();
    }
    return resultat;
}

/////////////////////////// main()
void main(int argc,char* argv[]){
    token=_lire_token();
    boolean res=true;
    ///////////////////////////////////////////
    char str[100]="";
    strcpy(str,argv[0]);
    ///////////////////////////////////////////
    //printf("argv[0] : %s\n",str);
    ///////////////////////////////////////////
    FILE *fp = fopen(str, "r"); 
    int ch = getc(fp); 
    while((ch!=EOF) &&(token!=END)/*&& (token!=BEG_IN)*/){
        if(!_prove()){
            res=false;
        }
        token=_lire_token();
        ch = getc(fp);
    }
    if(res==true){
        printf("a good prog\n");
    }
    else{
        printf("not a good prog at all\n");
    }
}