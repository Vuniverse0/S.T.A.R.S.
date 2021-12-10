//
// Created by vuniverse on 11/22/21.
//

#include "Metadata.h"


MetaDataBody::MetaDataBody(const json &j)
{
    *this = from_json(j);
}

MetaDataObject::MetaDataObject(const json &j)
{
    *this = from_json(j);
}

MetaDataObject::MetaDataObject(const Body& a_body, const Type& a_type, const Sets& a_sets, s a_file,
                               const uint16_t& a_id, s a_name):
    body{a_body},
    type{a_type},
    sets{a_sets},
    file{a_file},
    id{a_id},
    name{a_name}
{

}

MetaDataBody::MetaDataBody(f a_speed, f a_bsize, f a_spin, const bool& a_direction, const bool& a_spin_direction):
    speed{a_speed},
    bsize{a_bsize},
    spin{a_spin},
    direction{a_direction},
    spin_direction{a_spin_direction}
{
}

MetaDataBody MetaDataBody::from_json(const json &j)
{
    MetaDataBody p{};
    j.at("speed").get_to(p.speed);
    j.at("size").get_to(p.bsize);
    j.at("spin").get_to(p.spin);
    j.at("direction").get_to(p.direction);
    j.at("spin_direction").get_to(p.spin_direction);
    return p;
}

void MetaDataBody::to_json(json &j)
{
    j = json{{"speed", speed},
             {"size", bsize},
             {"spin", spin},
             {"direction", direction},
             {"spin_direction", spin_direction}};
}

MetaDataObject MetaDataObject::from_json(const json &j)
{
    MetaDataObject p{};
    j.at("body").get_to(p.body);
    j.at("type").get_to(p.type.member);
    j.at("set first").get_to(p.sets.first.set);
    j.at("set second").get_to(p.sets.second.set);
    j.at("id").get_to(p.id);
    j.at("file").get_to(p.file);
    j.at("name").get_to(p.name);
    return p;
}

void MetaDataObject::to_json(json &j)
{
    j = json{{"body", body},
             {"type", type.member},
             {"set first", sets.first.set},
             {"set second", sets.second.set},
             {"id", id},
             {"file", file},
             {"name", name}};
}