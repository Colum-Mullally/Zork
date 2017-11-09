#include "item.h"
#include "ZorkUL.h"


Item::Item (string inDescription, bool inholdable, int inmod){
    description = inDescription;
    holdable = inholdable;
    mod = inmod;
}
string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

int Item::getMod(){
    return mod;
}

bool Item::getHold(){
    return holdable;
}
Item::~Item() {

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/resource/Break.wav"));
    player->setVolume(50);
    player->play();
}
