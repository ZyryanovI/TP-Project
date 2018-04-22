#pragma once
#include <memory>
#include <vector>

using std::vector;

/**
 * \brief Класс IComposite
 * Объекты Game, Player, Point, Tower, Component являются наследниками компоновщика.
 * В компоновщике содержится вектор детей - указателей на другой компоновщик
 *
 */

class IComposite {
public:
    /**
     * \brief Функция, обновляющаяя состояние объекта
     * Переопределена в наследниках класса IComposite,
     * к которым относятся: Game, Player, Point, Tower, Component
     * @param dtime - время прошедшее с предыдущего запуска Update
     */
    virtual void Update(double dtime);

    /**
     * \brief Функция DeepUpdate
     * Вызывает Update(dt) текущего объекта и DeepUpdate(dt) его детей.
     * Она вызывается у CGame, который по цепочке передает его остальным объектам.

     * @param dtime - время прошедшее с предыдущего запуска Update
     */

    void DeepUpdate(double dtime);

    /**
     * \brief Добавление ребенка
     * @param new_child
     */

    void AddChild(IComposite* new_child);

    /**
     * \brief Удаление ребенка
     * @param child
     */

    void RemoveChild(IComposite* child);

private:
    std::vector<IComposite*> _children; // не забыть проверить, что не будет проблем с тем что private

};

