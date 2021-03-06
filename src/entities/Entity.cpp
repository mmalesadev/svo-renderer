#include "Entity.h"

Entity::Entity(unsigned int id, std::string name, std::unique_ptr<TransformComponent>& transformComponent, 
    std::unique_ptr<GraphicsComponent>& graphicsComponent, std::unique_ptr<CameraComponent>& cameraComponent)
    : transformComponent_(std::move(transformComponent)), 
    graphicsComponent_(std::move(graphicsComponent)), 
    cameraComponent_(std::move(cameraComponent)),
    id_(id),
    name_(name)
{
    SPDLOG_DEBUG(spdlog::get("logger"), "Constructing entity. id: {0}, name: {1}", id, name);
}

Entity::~Entity()
{
    SPDLOG_DEBUG(spdlog::get("logger"), "Destructing entity.");
}

Entity::Entity(const Entity &)
{
    SPDLOG_DEBUG(spdlog::get("logger"), "Copy constructing entity.");
}

std::unique_ptr<TransformComponent>& Entity::getTransformComponent()
{
    return transformComponent_;
}

std::unique_ptr<GraphicsComponent>& Entity::getGraphicsComponent()
{
    return graphicsComponent_;
}

std::unique_ptr<CameraComponent>& Entity::getCameraComponent()
{
    return cameraComponent_;
}
