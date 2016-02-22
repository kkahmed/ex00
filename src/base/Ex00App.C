#include "Ex00App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Ex00App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Ex00App::Ex00App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Ex00App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Ex00App::associateSyntax(_syntax, _action_factory);
}

Ex00App::~Ex00App()
{
}

// External entry point for dynamic application loading
extern "C" void Ex00App__registerApps() { Ex00App::registerApps(); }
void
Ex00App::registerApps()
{
  registerApp(Ex00App);
}

// External entry point for dynamic object registration
extern "C" void Ex00App__registerObjects(Factory & factory) { Ex00App::registerObjects(factory); }
void
Ex00App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Ex00App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Ex00App::associateSyntax(syntax, action_factory); }
void
Ex00App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
