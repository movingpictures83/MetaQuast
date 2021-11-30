#ifndef METAQUASTPLUGIN_H
#define METAQUASTPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class MetaQuastPlugin : public Plugin
{
public: 
 std::string toString() {return "MetaQuast";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
