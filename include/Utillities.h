#pragma once

enum TextureRcs {
    PlayBackground,
    truck,
    redCar,
    yellowCar,
    hummer,
    mustang,
    ground_1,
    ground_2,
    ground_3,
    ground_4,
    ground_5,
    ground_8,
    ground_9,
    barrel,
    coin,
    icon,
    dust,
    box,
    healthBar,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    explosion,
    water,
    finishLine,
    rock,
    rollerCoaster,
    fence,
    letsGo,
    messageOne,
    messageTwo,
    messageThree,
    OpenMenuBackground,
    musicIcons,
    Buttons,
    OpenMenuButtons,
    TexturesCount,
};

enum SoundRcs {
    OpenSound,
    SoundsCount
};

enum Menus {
    OpenGameMenu,
    Play,
    HowToPlayMenu,
    ChooseCarMenu,
    InGameMenu,
    MenusCount
};

enum groupIndex {
    Collide = 3,
    DontCollide = -3,
    Circle = -3,
    GroundCollide = 1,
    SensorCollide = -9,
    FloorCollide = -11,
    BoundariesCollide = -10,
};