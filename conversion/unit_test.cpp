/* (C) Programmed by:
   Antonio Jimenez Martínez
   Andrés Ortiz Corrales
   Mariano Palomo Villafranca  */
/*
Fermath Project: Unit test
Version:0.6
*/

//This program tests the class unit

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
#include "include/templates.h"
#include "include/operations.h"
#include "include/unit.h"
#include "include/functions.h"

main() {
    cout<<"Fermath Unit Test V0.6"<<endl;
    cout<<"this program will create a file called unit.test"<<endl;
    operations conv;
    int id=0;
    unit kg(string("kilogramos"),string("kg"),conv); //standard unit of magnitude
    conv.add_operation(4,1000);
    unit g(string("gramos"),string("g"),conv);
    conv.clear();
    conv.add_operation(3,1000);
    unit tonelada(string("toneladas"),string("T"),conv);
    double x;
    cout<<"write a number:";
    cin>>x;
    x=tonelada.standard_unit_value(x); //turns T into kg;
    cout<<kg.get_name()<<":"<<x<<endl;
    x=g.value_from_standard_unit(x); //turns kg into g;
    cout<<g.get_name()<<":"<<x<<"  (";
    out_science(x);
    cout<<")"<<endl;
    x=tonelada.convert_from(x,g);   //turns g into T
    cout<<tonelada.get_name()<<":"<<x<<endl;
    g.add_name("gramillo");
    kg.add_name("unkilo");
    ofstream out("unit.test");
    kg.write_unit(out);
    g.write_unit(out);
    tonelada.write_unit(out); //writes the 3 units
    out.close();
    cout<<"Units from file:"<<endl;
    ifstream input("unit.test");
    unit kg2(input);
    unit g2(input);
    input.close(); //read the 2 first
    cout<<g2<<endl;
    cout<<endl<<kg2<<endl;
    cout<<endl<<"Gramillo is a name for g?"<<g.have_name("gramillo");
    cout<<endl<<"Gramillo is a name for kg?"<<kg.have_name("gramillo")<<endl;
    cout<<endl<<"kg==g: "<<(kg==g)<<endl;
    cout<<endl<<"g==g2: "<<(g==g2)<<endl;
    write_vector(kg.get_names());
    cout<<endl;
    kg2.add_name("kiloprueba1");
    kg2.add_name("kiloprueba2");
    kg=kg+kg2;
    cout<<(kg==kg2)<<endl;
    cout<<"added names to kg using operator +"<<endl;
    write_vector(kg.get_names());
    cout<<endl;
    return 0;
}