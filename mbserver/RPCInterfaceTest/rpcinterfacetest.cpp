/*
 * MediaBlocks
 *
 * Copyright (C) 2011 - 2015 Bruno Pierucki
 *
 * Author: Bruno Pierucki <bp@nebenwelten.net>
 *
 */
//// begin includes
//// end includes

//// begin MediaBlocks specific includes
#include <QObject>
#include <QtTest>
//// end MediaBlocks specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace MediaBlocks {
namespace Test{
/**
 * \class RPCInterfaceTest
 * \ingroup group_rpc_interface_test
 *
 * \brief
 *
 */
class RPCInterfaceTest : public QObject
{
	Q_OBJECT
	//// begin RPCInterfaceTest public member methods
public:
	/// Constructor
	RPCInterfaceTest();
	/// Destructor
	virtual ~RPCInterfaceTest();
	//// end RPCInterfaceTest public member methods

	//// begin RPCInterfaceTest public member methods (internal use only)
public:
	//// end RPCInterfaceTest public member methods (internal use only)

	//// begin RPCInterfaceTest protected member methods
protected:
	//// end RPCInterfaceTest protected member methods

	//// begin RPCInterfaceTest protected member methods (internal use only)
protected:
	//// begin RPCInterfaceTest protected member methods (internal use only)

	//// begin RPCInterfaceTest private member methods
private:
	//// end RPCInterfaceTest private member methods

	//// begin RPCInterfaceTest public member
public:
	//// end RPCInterfaceTest public member

	//// begin RPCInterfaceTest protected member
protected:
	//// end RPCInterfaceTest protected member

	//// begin RPCInterfaceTest private member
private:
	//// end RPCInterfaceTest private member

	//// begin RPCInterfaceTest public slots
public slots:
	//// end RPCInterfaceTest public slots

	//// begin RPCInterfaceTest protected slots
protected slots:
	//// end RPCInterfaceTest protected slots

	//// begin RPCInterfaceTest private slots
private slots:
	void test1();
	//// end RPCInterfaceTest private slots

	//// begin RPCInterfaceTest signals
signals:
	//// end RPCInterfaceTest signals
};
}	// namespace Test
}   // namespace MediaBlocks


/*
 * MediaBlocks
 *
 * Copyright (C) 2011 - 2015 Bruno Pierucki
 *
 * Author: Bruno Pierucki <bp@nebenwelten.net>
 */

//// begin includes
//// end includes

//// begin MediaBlocks specific includes
//// end MediaBlocks specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin RPCInterfaceTest static definitions
//// end RPCInterfaceTest static definitions

//// begin RPCInterfaceTest static functions
//// end RPCInterfaceTest static functions

//// begin RPCInterfaceTest public member methods
/**********************************************************************************************************************/
MediaBlocks::Test::RPCInterfaceTest::RPCInterfaceTest()
	:QObject() {
}
/**********************************************************************************************************************/
MediaBlocks::Test::RPCInterfaceTest::~RPCInterfaceTest() {
}
//// end RPCInterfaceTest public member methods

//// begin RPCInterfaceTest public member methods (internal use only)
//// end RPCInterfaceTest public member methods (internal use only)

//// begin RPCInterfaceTest protected member methods
//// end RPCInterfaceTest protected member methods

//// begin RPCInterfaceTest protected member methods (internal use only)
//// begin RPCInterfaceTest protected member methods (internal use only)

//// begin RPCInterfaceTest private member methods
//// end RPCInterfaceTest private member methods

//// begin RPCInterfaceTest public slots
//// end RPCInterfaceTest public slots

//// begin RPCInterfaceTest protected slots
//// end RPCInterfaceTest protected slots

//// begin RPCInterfaceTest private slots
void MediaBlocks::Test::RPCInterfaceTest::test1() {
	QVERIFY(true);
}
//// end RPCInterfaceTest private slots


QTEST_APPLESS_MAIN(MediaBlocks::Test::RPCInterfaceTest)

#include "rpcinterfacetest.moc"
