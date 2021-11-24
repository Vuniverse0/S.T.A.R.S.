//
// Created by vuniverse on 11/22/21.
//

#include "Metadata.h"


void to_json(json& j, const MetaDataObject& p)
{
    j = json{{"body", p.body},
             {"type", p.type.member},
             {"set first", p.sets.first.set},
             {"set second", p.sets.second.set},
             {"file", p.file}};
}

void from_json(const json& j, MetaDataObject& p)
{
    j.at("body").get_to(p.body);
    j.at("type").get_to(p.type.member);
    j.at("set first").get_to(p.sets.first.set);
    j.at("set second").get_to(p.sets.first.set);
    j.at("file").get_to(p.file);
}

void to_json(json& j, const MetaDataBody& p)
{
    j = json{{"speed", p.speed},
             {"size", p.bsize},
             {"spin", p.spin}};
}

void from_json(const json& j, MetaDataBody& p)
{
    j.at("speed").get_to(p.speed);
    j.at("size").get_to(p.bsize);
    j.at("spin").get_to(p.spin);
}