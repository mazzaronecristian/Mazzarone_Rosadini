//
// Created by cristian on 28/02/21.
//

#include "../header/Character.h"

Character::Character(int hp, int damage, sf::Time AnimTime, float speed, int sizeX, int sizeY): hp(hp), damage(damage), AnimTime(AnimTime), speed(speed), source(sizeX, sizeY){}

bool Character::load(const std::string &tileSet, sf::Vector2f position) {
    if(!Character::tileSet.loadFromFile(tileSet))
        return false;
    sprite.setTexture(Character::tileSet);
    sprite.setPosition(position);
    source.x = 1;
    source.y = (stay);
    sprite.scale(1.4, 1.4);
    sprite.setTextureRect(sf::IntRect (source.x * 32, source.y * 32, 32, 32));
    return true;
}

void Character::movement(sf::Vector2f direction) {
    source.y = right;
    sprite.move(direction);

    if(AnimClock.getElapsedTime() > AnimTime){
        sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        //Animation
        source.x++;
        if(source.x * 32 >= 256/*sprite.getTexture()->getSize().x*/)
            source.x = 0;
        AnimClock.restart();
    }
}

void Character::moveUp() {
    if(source.y == stay)
        source.y = right;
    sprite.move(0, -speed);

    if(AnimClock.getElapsedTime() > AnimTime){
        sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        //Animation
        source.x++;
        if(source.x * 32 >= 256/*sprite.getTexture()->getSize().x*/)
            source.x = 0;
        AnimClock.restart();
    }
}

void Character::moveDown() {
    if(source.y == stay)
        source.y = right;
    sprite.move(0, speed);

    if(AnimClock.getElapsedTime() > AnimTime){
        sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        //Animation
        source.x++;
        if(source.x * 32 >= 256/*sprite.getTexture()->getSize().x*/)
            source.x = 0;
        AnimClock.restart();
    }
}

void Character::moveLeft() {
    source.y = left;
    sprite.move(-speed, 0);

    if(AnimClock.getElapsedTime() > AnimTime){
        sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        //Animation
        source.x++;
        if(source.x * 32 >= 256/*sprite.getTexture()->getSize().x*/)
            source.x = 0;
        AnimClock.restart();
    }
}

void Character::moveRight() {
    source.y = right;
    sprite.move(speed, 0);

    if(AnimClock.getElapsedTime() > AnimTime){
        sprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        //Animation
        source.x++;
        if(source.x * 32 >= 256/*sprite.getTexture()->getSize().x*/)
            source.x = 0;
        AnimClock.restart();
    }
}

//getter
int Character::getHp() const{
    return hp;
}

int Character::getDamage() const{
    return damage;
}

//setter
void Character::setHp(int hp) {
    Character::hp = hp;
}

void Character::setDamage(int damage) {
    Character::damage = damage;
}

void Character::receiveDamage(int damage) {
    Character::hp -= damage;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}
