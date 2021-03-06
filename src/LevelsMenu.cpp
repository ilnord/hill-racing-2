#include "LevelsMenu.hpp"

LevelsMenu::LevelsMenu() {

    position = 0;
    font.loadFromFile("LemonMilk.otf"); 

    level1.setFont(font);
    level1.setCharacterSize(50);
    level1.setStyle(sf::Text::Bold);
    level1.setColor(sf::Color::White);
    level1.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*3);
    level1.setString("EASY BEASY"); 
    levels.push_back(&level1);

    level2.setFont(font);
    level2.setCharacterSize(50);
    level2.setStyle(sf::Text::Bold);
    level2.setColor(sf::Color::White);
    level2.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*5);
    level2.setString("VANILLA");  
    levels.push_back(&level2);
    
    level3.setFont(font);
    level3.setCharacterSize(50);
    level3.setStyle(sf::Text::Bold);
    level3.setColor(sf::Color::White);
    level3.setPosition(SCREEN_WIDTH/3, (SCREEN_HEIGHT/10)*7);
    level3.setString("HARD AS ROCK");  
    levels.push_back(&level3);
  }

    

  int LevelsMenu::open(sf::RenderWindow &window, int screen)  {

    while (window.isOpen()) {
        int process = processEvents(window);    
        window.clear();

        for(size_t i = 0; i < levels.size(); i++) {
          if(i == position) {
            levels[i]->setColor(sf::Color::Red);
          } 
          else {
            levels[i]->setColor(sf::Color::White);
          }
        }

        
        for(auto t : levels)
            window.draw(*t);
        window.display();

        return process;
    }

    //Temporary solution
    return -1;
}



  int LevelsMenu::processEvents(sf::RenderWindow& window) {

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyReleased){
        switch (event.key.code){
            
        case sf::Keyboard::Return:
          if(position == 0) {
            return GAME_DIFFICULTY_EASY;
          } 
          if(position == 1) {
            return GAME_DIFFICULTY_NORMAL;
          }
          if(position == 2) {
            return GAME_DIFFICULTY_HARD;
          }

        case sf::Keyboard::Escape:
           return GAMESTATE_MAINMENU;
           
        case sf::Keyboard::Up: 
            if(position > 0){
             position--;
            }

        return GAMESTATE_LEVELS;

        case sf::Keyboard::Down:
           if(position < levels.size() - 1) {
             position++;
           }
         return GAMESTATE_LEVELS;
        }
      }
        
    }

    return GAMESTATE_LEVELS;
  }