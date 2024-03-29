�
�sAYc           @   sq   d  Z  d d l Z d d l Z d d l Z d d l Z d d l j Z d �  Z d �  Z	 d e
 f d �  �  YZ d S(   s+   Visual Studio user preferences file writer.i����Nc         C   s�   d |  k s d |  k r |  St  j j d d � j t  j � } xN | D]F } t  j j | |  � } t  j j | � rD t  j | t  j	 � rD | SqD W|  S(   s{  If there are no slashes in the command given, this function
     searches the PATH env to find the given command, and converts it
     to an absolute path.  We have to do this because MSVS is looking
     for an actual file to launch a debugger on, not just a command
     line.  Note that this happens at GYP time, so anything needing to
     be built needs to have a full path.t   /s   \t   PATHt    (
   t   ost   environt   gett   splitt   pathsept   patht   joint   isfilet   accesst   X_OK(   t   commandt   pathsR   t   item(    (    s{   C:\projects\atom\apm\node_modules\atom-package-manager\node_modules\npm\node_modules\node-gyp\gyp\pylib\gyp\MSVSUserFile.pyt   