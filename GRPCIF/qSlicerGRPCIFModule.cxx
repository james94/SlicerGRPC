/*==============================================================================

  Copyright (c) The Intervention Centre
  Oslo University Hospital, Oslo, Norway. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Rafael Palomar (The Intervention Centre,
  Oslo University Hospital) and was supported by The Research Council of Norway
  through the ALive project (grant nr. 311393).

==============================================================================*/

#include "qSlicerGRPCIFModule.h"


// Qt includes
#include <QDebug>

// GRPCIF Logic includes
#include "vtkSlicerGRPCIFLogic.h"

// GRPCIF Widgets includes
#include "qMRMLMarkupsTestLineWidget.h"

// Markups Widgets includes
#include "qMRMLMarkupsOptionsWidgetsFactory.h"

#include <qSlicerModuleManager.h>
#include <qSlicerApplication.h>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerGRPCIFModulePrivate
{
public:
  qSlicerGRPCIFModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerGRPCIFModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerGRPCIFModulePrivate::qSlicerGRPCIFModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerGRPCIFModule methods

//-----------------------------------------------------------------------------
qSlicerGRPCIFModule::qSlicerGRPCIFModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerGRPCIFModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerGRPCIFModule::~qSlicerGRPCIFModule()
{
}

//-----------------------------------------------------------------------------
bool qSlicerGRPCIFModule::isHidden() const
{
  // The module has no GUI.
  // Widget options will be shown in Markups module.
  return true;
}

//-----------------------------------------------------------------------------
QString qSlicerGRPCIFModule::helpText() const
{
  return "This module contains fundamental markups to be used in the Slicer-Liver extension.";
}

//-----------------------------------------------------------------------------
QString qSlicerGRPCIFModule::acknowledgementText() const
{
  return "This work has been partially funded by The Research Council of Norway (grant nr. 311393)";
}

//-----------------------------------------------------------------------------
QStringList qSlicerGRPCIFModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("Rafael Palomar (Oslo University Hospital / NTNU)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerGRPCIFModule::icon() const
{
  return QIcon(":/Icons/GRPCIF.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerGRPCIFModule::categories() const
{
  return QStringList() << "Testing.TestCases";
}

//-----------------------------------------------------------------------------
QStringList qSlicerGRPCIFModule::dependencies() const
{
  return QStringList() << "Markups";
}

//-----------------------------------------------------------------------------
void qSlicerGRPCIFModule::setup()
{
  this->Superclass::setup();

  // This is a test class, therefore we do not register anything if
  // not in testing mode (to avoid cluttering the markups module).
  bool isTestingEnabled = qSlicerApplication::testAttribute(qSlicerCoreApplication::AA_EnableTesting);
  if (!isTestingEnabled)
    {
    return;
    }

  // Create and configure the options widgets
  auto optionsWidgetFactory = qMRMLMarkupsOptionsWidgetsFactory::instance();
  optionsWidgetFactory->registerOptionsWidget(new qMRMLMarkupsTestLineWidget());
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerGRPCIFModule::createWidgetRepresentation()
{
  return nullptr;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerGRPCIFModule::createLogic()
{
  // This is a test class, therefore we do not register anything (to avoid cluttering the markups module)
  // unless the application is in testing mode.
  bool isTestingEnabled = qSlicerApplication::testAttribute(qSlicerCoreApplication::AA_EnableTesting);
  if (!isTestingEnabled)
    {
    return nullptr;
    }

  return vtkSlicerGRPCIFLogic::New();
}
