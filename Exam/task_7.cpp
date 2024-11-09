#include <iostream>
#include <vector>
#include <string>

class Quest {
public:
    std::string questName;
    std::string description;
    int requiredLevel;
    int currentProgress;
    int maxProgress;
    int reward;

    // Конструктор для ініціалізації квесту
    Quest(std::string name, std::string desc, int level, int progress, int maxProgress, int reward)
        : questName(name), description(desc), requiredLevel(level),
          currentProgress(progress), maxProgress(maxProgress), reward(reward) {}

    // Метод для перевірки завершення квесту
    bool isCompleted()  {
        return currentProgress >= maxProgress;
    }

    // Метод для оновлення прогресу квесту
    void updateProgress(int progress) {
        if (currentProgress + progress <= maxProgress) {
            currentProgress += progress;
        } else {
            currentProgress = maxProgress;
        }
    }

    // Метод для виведення інформації про квест
    void showQuestDetails()  {
        std::cout << "Quest Name: " << questName << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Required Level: " << requiredLevel << std::endl;
        std::cout << "Progress: " << currentProgress << "/" << maxProgress << std::endl;
        std::cout << "Reward: " << reward << " experience points or gold" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
};

class Character {
private:
    std::string name;
    int level;
    int experience;
    std::vector<Quest> activeQuests;

public:
    // Конструктор для ініціалізації персонажа
    Character(std::string name, int level)
        : name(name), level(level), experience(0) {}

    // Метод для прийняття квесту
    void acceptQuest(const Quest &quest) {
        if (level >= quest.requiredLevel) {
            activeQuests.push_back(quest);
            std::cout << name << " has accepted the quest: " << quest.questName << std::endl;
        } else {
            std::cout << name << " cannot accept the quest " << quest.questName << " due to insufficient level." << std::endl;
        }
    }

    // Метод для завершення квесту
    void completeQuest(Quest &quest) {
        if (quest.isCompleted()) {
            experience += quest.reward;
            std::cout << name << " has completed the quest: " << quest.questName << " and earned " << quest.reward << " experience points." << std::endl;
        } else {
            std::cout << "Quest " << quest.questName << " is not yet completed." << std::endl;
        }
    }

    // Метод для показу активних квестів
    void showActiveQuests()  {
        if (activeQuests.empty()) {
            std::cout << name << " has no active quests." << std::endl;
        } else {
            std::cout << name << "'s Active Quests:" << std::endl;
            for (const auto& quest : activeQuests) {
                quest.showQuestDetails();
            }
        }
    }

    // Метод для отримання досвіду
    int getExperience()  {
        return experience;
    }

    // Метод для отримання рівня
    int getLevel()  {
        return level;
    }

    // Метод для збільшення рівня
    void levelUp() {
        level++;
        std::cout << name << " has leveled up to level " << level << "!" << std::endl;
    }
};

int main() {
    // Створення квестів
    Quest quest1("Find the Lost Artifact", "Find and bring back the lost artifact", 5, 0, 10, 100);
    Quest quest2("Defeat the Bandits", "Defeat the bandits that have been terrorizing the village", 3, 0, 5, 50);
    Quest quest3("Explore the Haunted Forest", "Explore the haunted forest and report any findings", 7, 0, 20, 150);

    // Створення персонажа
    Character character1("Mage", 4);

    // Прийняття квестів
    character1.acceptQuest(quest1);
    character1.acceptQuest(quest2);

    // Оновлення прогресу квесту
    quest2.updateProgress(3);
    quest2.updateProgress(2);

    // Показ активних квестів
    character1.showActiveQuests();

    // Завершення квесту
    character1.completeQuest(quest2);  // Завершено квест

    // Виведення досвіду
    std::cout << "Total Experience: " << character1.getExperience() << std::endl;

    // Підвищення рівня персонажа
    character1.levelUp();

    return 0;
}
