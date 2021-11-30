#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MetaQuastPlugin.h"

void MetaQuastPlugin::input(std::string file) {
 inputfile = file;
  std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   if (key.size() != 0)
   parameters[key] = value;
   else
           break;
 }
}

void MetaQuastPlugin::run() {
   
}

void MetaQuastPlugin::output(std::string file) {
 // spades.py -o 02_MetaQuast -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
	std::string command = "metaquast.py "+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" -r "+std::string(PluginManager::prefix())+"/"+parameters["reference"]+" -o "+file+"; cp "+file+"/summary/TXT/* "+file+"/../";
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<MetaQuastPlugin> MetaQuastPluginProxy = PluginProxy<MetaQuastPlugin>("MetaQuast", PluginManager::getInstance());
