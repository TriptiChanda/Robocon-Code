es\node-gyp\gyp\pylib\gyp\MSVSUserFile.pyt   AddDebugSettingsN   sB    
,
c         C   s�   d g } x0 t  |  j j �  � D] \ } } | j | � q Wd i |  j j �  d 6|  j d 6| g } t j | |  j	 d d �d S(   s   Writes the user file.t   Configurationst   VisualStudioUserFilet   VersionR"   t   encodings   Windows-1252N(
   t   sortedR   RC   R   R   t   ProjectVersionR   t   easy_xmlt   WriteXmlIfChangedR   (   R   t   configst   configt   spect   content(    (    s{   C:\projects\atom\apm\node_modules\atom-package-manager\node_modules\npm\node_modules\node-gyp\gyp\pylib\gyp\MSVSUserFile.pyt   WriteIfChanged�   s    	"
	(   t   __name__t
   __module__t   __doc__R    R#   RN   R[   (    (    (    s{   C:\projects\atom\apm\node_modules\atom-package-manager\node_modules\npm\node_modules\node-gyp\gyp\pylib\gyp\MSVSUserFile.pyR   6   s   		8(   R^   R   R   RD   t
   gyp.commont   gypt   gyp.easy_xmlRU   R   R   t   obj