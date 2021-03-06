/* (C) Programmed by:
   Antonio Jimenez Martínez
   Andrés Ortiz Corrales
   Mariano Palomo Villafranca  */
/*
Fermath Project:Data Source Class
Version:0.9
*/

#include "glossary.h"
//This class controls I/O and relations between sources and glossary

class data_src{
private:
glossary names; //stores names for units and magnitudes
unit_source src; //stores basic and complex units and magnitudes
public:
data_src(){
}
data_src(const unit_source &src2,const glossary &names2){
names=names2;
src=src2;
}

magnitude_id add_magnitude(const string &n,const vector<string> &v){
magnitude_id id;
magnitude m(n); //new magnitude the name
id=src.add_magnitude(m);//add magnitude and returns id
names.add_names(id,v); //adds all names of magnitude to the glossary
names.add_magnitude_name(n);//adds the principal name of magnitude (if it isnt in v)
return id;
}

unit_id add_unit(const complex_unit &u,magniude_id id,vector<string> &v){
unit id uid;
//TODO


}




private:
void check(){
//TODO
}

}
