#include <gtest/gtest.h>
#include "AllClasses.h"
#include "Tower.h"
#include "Producer.h"
#include "Game.h"
#include "Point.h"
#include "TowerComponents.h"


TEST(PrjTest, TestCGame){
    CGame* game1 = CGame::Instance();
    CGame* game2 = CGame::Instance();
    EXPECT_EQ(game1, game2);

    CGame::DeleteInstance();

}

TEST(PrjTest, TestProducer){
    IProducer* producer = new CProducer;
    IFactory* fac = new CFactoryEnlarger;
    CPlayer pl;
    pl.money = 30;
    CPoint po;


    producer->SetFactoryAndPlayer(&pl, fac);
    EXPECT_TRUE(producer->IsAbleToCreate());
    CTower* tower = producer->Create(&po);
    EXPECT_FALSE(producer->IsAbleToCreate());
    delete tower;
    delete producer;
}

TEST(PrjTest, TestCDAndCost){
    IFactory* fac = new CFactoryEnlarger;
    CPlayer pl;
    pl.money = 30;
    CPoint po;

    EXPECT_EQ(20, fac->GetCD());
    EXPECT_EQ(20, fac->GetCOST());
}

TEST(PrjTest, TwoProducersOneFactory) {
    IProducer* producer1 = new CProducer;
    IProducer* producer2 = new CProducer;

    CPlayer pl;
    CPoint po;
    pl.money = 1000;

    {
        IFactory* fac = new CFactoryMissile;
        producer1->SetFactoryAndPlayer(&pl, fac);
        producer2->SetFactoryAndPlayer(&pl, fac);
    }

    CTower* tower1 = producer1->Create(&po);
    delete producer1;
    CTower* tower2 = producer2->Create(&po);

    EXPECT_NE(tower1, nullptr);
    EXPECT_NE(tower2, nullptr);
    EXPECT_NE(tower1, tower2);

    delete tower1;
    delete tower2;
    delete producer2;
}

TEST(PrjTest, Composite) {
    class CFoo : public IComposite {
    public:
        double x;
        CFoo(): x(0.0) {}

        void Update(double dt) override {
            x += dt;
        }
    };

    CFoo x;
    CFoo y;
    CFoo z;
    x.AddChild(static_cast<IComposite*>(&y));
    y.AddChild(static_cast<IComposite*>(&z));
    x.DeepUpdate(0.1);
    y.DeepUpdate(0.5);

    EXPECT_EQ(x.x, 0.1);
    EXPECT_EQ(y.x, 0.6);
    EXPECT_EQ(z.x, 0.6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



