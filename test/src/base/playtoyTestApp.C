//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "playtoyTestApp.h"
#include "playtoyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<playtoyTestApp>()
{
  InputParameters params = validParams<playtoyApp>();
  return params;
}

playtoyTestApp::playtoyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  playtoyApp::registerObjectDepends(_factory);
  playtoyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  playtoyApp::associateSyntaxDepends(_syntax, _action_factory);
  playtoyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  playtoyApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    playtoyTestApp::registerObjects(_factory);
    playtoyTestApp::associateSyntax(_syntax, _action_factory);
    playtoyTestApp::registerExecFlags(_factory);
  }
}

playtoyTestApp::~playtoyTestApp() {}

void
playtoyTestApp::registerApps()
{
  registerApp(playtoyApp);
  registerApp(playtoyTestApp);
}

void
playtoyTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
playtoyTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
playtoyTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
playtoyTestApp__registerApps()
{
  playtoyTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
playtoyTestApp__registerObjects(Factory & factory)
{
  playtoyTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
playtoyTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  playtoyTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
playtoyTestApp__registerExecFlags(Factory & factory)
{
  playtoyTestApp::registerExecFlags(factory);
}
