#include "SpriteRenderingSystem.h"
#include <QGraphicsScene>

void SpriteRenderingSystem::render()
{
    if(!m_scene)
        return;

    auto entities = getEntities();
    for(auto& entity : entities)
    {
        auto& item = entity.getComponent<SpriteComponent>().item;
        auto& pos = entity.getComponent<PositionComponent>().pos;

        if(m_scene->items().indexOf(&item) == -1)
            m_scene->addItem(&item);

        item.setPos(pos);
        m_scene->update();
    }
}
