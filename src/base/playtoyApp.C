#include "playtoyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<playtoyApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

playtoyApp::playtoyApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  playtoyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  playtoyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  playtoyApp::registerExecFlags(_factory);
}

playtoyApp::~playtoyApp() {}

void
playtoyApp::registerApps()
{
  registerApp(playtoyApp);
}

void
playtoyApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
playtoyApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
playtoyApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
playtoyApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
playtoyApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
playtoyApp__registerApps()
{
  playtoyApp::registerApps();
}

extern "C" void
playtoyApp__registerObjects(Factory & factory)
{
  playtoyApp::registerObjects(factory);
}

extern "C" void
playtoyApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  playtoyApp::associateSyntax(syntax, action_factory);
}

extern "C" void
playtoyApp__registerExecFlags(Factory & factory)
{
  playtoyApp::registerExecFlags(factory);
}
