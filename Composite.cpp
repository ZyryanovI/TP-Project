#include "Composite.h"
#include <algorithm>

void IComposite::Update(double dtime) {}

void IComposite::DeepUpdate(double dtime) {
    this->Update(dtime);
    for(int i =0; i<_children.size(); ++i) {
        _children[i]->DeepUpdate(dtime);
    }
}

void IComposite::AddChild(IComposite* new_child) {
    _children.push_back(new_child);
}

void IComposite::RemoveChild(IComposite* child) {
    _children.erase(std::find(_children.begin(), _children.end(), child));
}