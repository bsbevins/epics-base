/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*
 *      $Id$
 *
 *      Author  Jeffrey O. Hill
 *              johill@lanl.gov
 *              505 665 1831
 */

#include "server.h"
#include "casPVIIL.h"

//
// casPVListChan::casPVListChan()
//
casPVListChan::casPVListChan (const casCtx &ctx) :
        casChannelI(ctx)
{
}

void casPVListChan::bindToClient ( 
    casCoreClient & client, casPVI & pv, caResId cidIn )
{
    this->bindToClientI ( client, pv, cidIn );
    this->pPV->installChannel ( *this );
}

//
// casPVListChan::~casPVListChan()
//
casPVListChan::~casPVListChan()
{
        this->pPV->removeChannel(*this);
        //
        // delete signal to PV occurs in
        // casChannelI::~casChannelI
        //
}

