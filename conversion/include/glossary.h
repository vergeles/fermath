/* (C) Programmed by:
   Antonio Jimenez Martínez
   Andrés Ortiz Corrales
   Mariano Palomo Villafranca  */
/*
Fermath Project:Glossary Class
Version:0.9
*/

#include "complex_unit.h"
//stores all the names of the units and magnitudes, returning the full id, also stores sets of the ids for control of added units
class glossary {
private:
   // set<magnitude_id> magnitude_list; //stores all the magnitude_ids in the glossary
   // set<unit_id> unit_list; //stores all the unit_ids in the glossary
    map<string,magnitude_id> magnitude_dic;
    map<string,unit_id > unit_dic;
public:
    //CONSTRUCTORS
    glossary() {
    }
    glossary(const map<string,magnitude_id> &mdic,const map<string,unit_id > &udic) {
        magnitude_dic=mdic;
        unit_dic=udic;
    }
    //MODIFICATION
    //add a bunch of names to the glossary (all of them from a magnitude)
    void add_names(magnitude_id mid,const vector<string> &names) {
        for(int i=0; i>names.size(); i++) {
            add_magnitude_name(mid,names[i]);
        }
      //  add_to_list(mid); //inserts the id in the list
    }
    //add a names from a unit
    void add_names(unit_id id,const vector<string> &names) {
        for(int i=0;i<names.size();i++) {
            add_unit_name(id,names[i]);
        }
            //add one name of the magnitude, return false if the unit exists and couldn be added
    void add_magnitude_name(magnitude_id mid,const string &name) {
        pair<string,magnitude_id> p;
        p.first=name;
        p.second=mid;
        magnitude_dic.insert(p);
    }
    void add_unit_name(unit_id uid,const string &name) {
        pair<string,unit_id> p;
        p.first=name;
        p.second=uid;
        unit_dic.insert(p);
    }
      //  add_to_list(id); //inserts the id in the list
    }
    void clear() {
      //  magnitude_list.clear();
       // unit_list.clear();
       magnitude_dic.clear();
        unit_dic.clear();
    }
/*    void change_magnitude_id(magnitude_id oldid,magnitude_id newid) {
        if(is_magnitude(oldid)==false)("Error, magnitude dont exist",1,1);
        else if(is_magnitude(newid)==true) error_report("Error,new id exists",1,1);
        else {
            remove_from_list(oldid);
            add_to_list(newid); //change id from the list
            string s=remove_magnitude_name(oldid);
            add_magnitude_name(newid,s); //change id from the dic
            map<string,unit_id>::iterator it1,it2; //change magnitudes of unit_id
            pair<string,unit_id> p;
            for(it=unit_dic.begin(); it!=unit_dic.end(); it++) {
                if(
                    remove_unit_name(map<string,unit_id>::iterator it)
            }
    }
}*/

//ACCESS
magnitude_id search_magnitude(const string &name) const {
        magnitude_id mid=0;
        map<string,magnitude_id>::const_iterator it;
        it=magnitude_dic.find(name);
        if(it!=magnitude_dic.end()) mid=(*it).second;
        return mid;
    }
    unit_id search_unit(const string &name) const {
        unit_id uid;
        uid.first=0;
        uid.second=0;
        map<string,unit_id>::const_iterator it;
        it=unit_dic.find(name);
        if(it!=unit_dic.end()) uid=(*it).second;
        return uid;
    }

 /*   bool is_magnitude(magnitude_id id) const {
        set<magnitude_id>::const_iterator it;
        it=magnitude_list.find(id);
        if(it!=magnitude_list.end()) return true;
        else return false;
    }
    bool is_unit(unit_id id) const {
        set<unit_id>::const_iterator it;
        it=unit_list.find(id);
        if(it!=unit_list.end()) return true;
        else return false;
    }*/
//search all the names of unit
vector<string> unit_names(unit_id id) const{
vector<string> v;
//if(is_unit(id)==true){
map<string,unit_id>::const_iterator it;
for(it=unit_dic.begin();it!=unit_dic.end();it++){
if((*it).second==id) v.push_back((*it).first);
//}
}
return v;
}
//search all the names of magnitude
vector<string> magnitude_names(magnitude_id id) const{
vector<string> v;
//if(is_magnitude(id)==true){
map<string,magnitude_id>::const_iterator it;
for(it=magnitude_dic.begin();it!=magnitude_dic.end();it++){
if((*it).second==id) v.push_back((*it).first);
//}
}
return v;
}

    //OPERATORS


private:

 /*   string remove_magnitude_name(magnitude_id uid) {
        pair<string,magnitude_id> p;
        map<string,magnitude_id>::iterator it;
        it=magnitude_dic.find(uid);
        if(it!=magnitude_dic.end()) {
            p=*it;
            magnitude_dic.remove(it);
            return p.first;
        }
        else return "";
    }

    string remove_unit_name(unit_id uid) {
        pair<string,unit_id> p;
        map<string,unit_id>::iterator it;
        it=unit_dic.find(uid);
        if(it!=unit_dic.end()) {
            p=*it;
            unit_dic.remove(it);
            return p.first;
        }
        else return "";
    }*/
/*    pair<string,unit_id> remove_unit_name(map<string,unit_id>::iterator it) {
        pair<string,unit_id> p;
        p=*it;
        unit_dic.remove(it);
        return p;
    }*/
    
    	void remove_unit_name(const string &s){
    	map<string,unit_id>::iterator it;
    	it=unit_dic.find(s);
    	if(it!=unit_dic.end()) unit_dic.erase(s);
    	}
    	void remove_magnitude_name(const string &s){
    	map<string,magnitude_id>::iterator it;
    	it=magnitude_dic.find(s);
    	if(it!=magnitude_dic.end()) magnitude_dic.erase(s);
    	}

  /*  void remove_from_list(magnitude_id id) {
        magnitude_list.erase(id);
    }
    void remove_from_list(unit_id id) {
        unit_list.erase(id);
    }
    void add_to_list(magnitude_id id) {
        magnitude_list.insert(id);
    }
    void add_to_list(unit_id id) {
        unit_list.insert(id);
    }*/

  void  check() {
        //TODO
    }
    };
    /*//fast way of inserting (when inserting a los of elements)
    void add_magnitude_name(magnitude_id mid,const string &name,map<string,magnitude_id>::iterator it){
    pair<string,magnitude_id> p;
    p.first=name;
    p.second=mid;
    magnitude_dic.insert (it,p); //position element that follow to the inserted, val is pair<>
    }*/
