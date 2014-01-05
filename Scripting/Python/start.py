import mokka
from util import *

#
# Internal
#

class _Internal():

  def __init__(self):
    import imp

    # Set attribute 'mokka.app'
    setattr(mokka, 'app', _qMokkaCoreApplicationInstance)
    # Set attribute 'mokka.data'
    setattr(mokka, 'data', _qMokkaCoreDataManagerInstance)

_internalInstance = _Internal()
