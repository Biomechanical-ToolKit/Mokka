import mokka
from util import *

#
# Internal
#

class _Internal():

  def __init__( self ):
    import imp

    # Set attribute 'mokka.app'
    setattr(mokka, 'app', _qMokkaCoreApplicationInstance)

_internalInstance = _Internal()
