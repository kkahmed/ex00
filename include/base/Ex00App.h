#ifndef EX00APP_H
#define EX00APP_H

#include "MooseApp.h"

class Ex00App;

template<>
InputParameters validParams<Ex00App>();

class Ex00App : public MooseApp
{
public:
  Ex00App(InputParameters parameters);
  virtual ~Ex00App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* EX00APP_H */
