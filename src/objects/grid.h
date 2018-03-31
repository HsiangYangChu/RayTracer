#ifndef GRID_H
#define GRID_H

#include <objects/compound.h>

class Grid: public Compound
{
public:
    typedef std::shared_ptr<Compound> Compound_ptr;
    typedef std::vector<Compound_ptr> Cells;
    typedef glm::ivec3 CellIndex;
    typedef glm::uvec3 CellSize;

    Grid(const std::string &);
    ~Grid() {}
    virtual bool hit(const Ray&, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    void setupCells();
    virtual void deserialize(TiXmlElement *)
    {
    }

protected:
    CellIndex getCellIndexByLocation(const vec3 &) const;
    const Compound_ptr &getCell(uint, uint, uint) const;
    Compound_ptr &getCell(uint, uint, uint);

    Cells cells;
    CellSize n;
};

#endif
