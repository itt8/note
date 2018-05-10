# WebRTC National Source #

https://source.codeaurora.org/


## depot_tools ##
https://source.codeaurora.org/quic/lc/chromium/tools/depot_tools

## replace url in gclient_scm.py ##
	class GitWrapper(SCMWrapper):
		"""Wrapper for Git"""
		name = 'git'
		remote = 'origin'

		cache_dir = None

		def __init__(self, url=None, *args, **kwargs):
		"""Removes 'git+' fake prefix from git URL."""
		if url.startswith('git+http://') or url.startswith('git+https://'):
			url = url[4:]
		url = url.replace('webrtc.googlesource.com/src.git', 'source.codeaurora.org/quic/lc/external/webrtc')
		url = url.replace('chromium.googlesource.com', 'source.codeaurora.org/quic/lc')
		url = url.replace('boringssl.googlesource.com', 'github.com/google')
		url = url.replace('swiftshader.googlesource.com', 'github.com/google')
		url = url.replace('source.codeaurora.org/quic/lc/external/swarming.client', 'github.com/AtariOS/swarming.client')
		url = url.replace('android.googlesource.com/platform/external/deqp', 'github.com/elongbug/deqp')
		SCMWrapper.__init__(self, url, *args, **kwargs)


## get source ##
	git clone https://source.codeaurora.org/quic/lc/chromium/tools/depot_tools
	#add depot_tools path to env PATH
	mkdir webrtc-checkout
	cd webrtc-checkout
	fetch --nohooks webrtc
	gclient sync

## update code ##
	git checkout master
	git pull origin master
	gclient sync

