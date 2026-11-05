PoolPayCoin (PPC)
=================

PoolPayCoin is a brand-new, fair-launch, CPU-mineable blockchain: its own genesis block
(launched 2026-11-04), not a fork of an existing live network. It's a Bitcoin Core 27
base with RandomX (`rx/pp`) as its proof-of-work instead of SHA-256, built and operated
by the team behind [pool-pay.com](https://pool-pay.com/).

- **White paper / project site:** https://coin.pool-pay.com/
- **Mining pool:** https://ppc.pool-pay.com/ ([pool source](https://github.com/newsmoneymaker/ppc-nodejs-pool))
- **Block explorer:** https://explorer.pool-pay.com/
- **Miner (poolpayminer, `rx/pp` support):** https://github.com/newsmoneymaker/poolpayminer
- **Pre-built node binaries (Linux x64, no build needed):** https://github.com/newsmoneymaker/poolpaycoin/releases/tag/v1.0.0

See the white paper above for the full technical writeup (supply/emission, the `rx/pp`
RandomX construction, the ASERT-from-genesis difficulty rationale, and an honest caveat
on what the custom Argon2 salt does and doesn't defend against). This repository is the
node daemon (`poolpaycoind`) and CLI (`poolpaycoin-cli`), forked from
[Satoshi Cash](https://github.com/scashnetwork/scash)'s own Bitcoin Core 27 + RandomX
base -- see the repository's git history for the exact PoolPayCoin-specific changes on
top of that base (own genesis/chain params, real 10 PPC subsidy, the ASERT-from-genesis
fix, and the project's own RandomX salt).

**Connecting your own node:** PoolPayCoin is brand new and doesn't have DNS seeds yet
(there's no established seed infrastructure for a chain this young). If your node starts
with 0 peers, add our node explicitly in your `poolpay.conf` (or as a command-line flag):

```
addnode=95.216.18.84:8350
```

or `poolpaycoind -addnode=95.216.18.84:8350`. That's our own pool/explorer node and is
currently the only well-known public peer on the network.

Everything below this point is upstream Bitcoin Core's own generic documentation.

Bitcoin Core integration/staging tree
=====================================

https://bitcoincore.org

For an immediately usable, binary version of the Bitcoin Core software, see
https://bitcoincore.org/en/download/.

What is Bitcoin Core?
---------------------

Bitcoin Core connects to the Bitcoin peer-to-peer network to download and fully
validate blocks and transactions. It also includes a wallet and graphical user
interface, which can be optionally built.

Further information about Bitcoin Core is available in the [doc folder](/doc).

License
-------

Bitcoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin/bitcoin/tags) are created
regularly from release branches to indicate new official, stable release versions of Bitcoin Core.

The https://github.com/bitcoin-core/gui repository is used exclusively for the
development of the GUI. Its master branch is identical in all monotree
repositories. Release branches and tags do not exist, so please do not fork
that repository unless it is for development reasons.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The CI (Continuous Integration) systems make sure that every pull request is built for Windows, Linux, and macOS,
and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Bitcoin Core's Transifex page](https://www.transifex.com/bitcoin/bitcoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.
